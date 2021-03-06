#pragma once

#include <basis/seadTypes.h>
#include <container/seadListImpl.h>
#include <prim/seadDelegate.h>
#include <prim/seadRuntimeTypeInfo.h>
#include <prim/seadSafeString.h>
#include <prim/seadTypedBitFlag.h>
#include "KingSystem/Utils/Thread/Event.h"
#include "KingSystem/Utils/Types.h"

namespace ksys::util {

class Task;
class TaskQueueBase;
class TaskRequest;
class TaskThread;

class TaskPostRunResult {
    SEAD_RTTI_BASE(TaskPostRunResult)
public:
    virtual ~TaskPostRunResult() = default;

    bool getResult() const { return mResult; }
    void setResult(bool result) { mResult = result; }

private:
    bool mResult = false;
};
KSYS_CHECK_SIZE_NX150(TaskPostRunResult, 0x10);

class TaskPostRunContext {
    SEAD_RTTI_BASE(TaskPostRunContext)
public:
    virtual ~TaskPostRunContext() = default;

    bool mCancelled;
    Task* mTask;
    void* mUserData;
};
KSYS_CHECK_SIZE_NX150(TaskPostRunContext, 0x20);

class TaskRemoveCallbackContext {
    SEAD_RTTI_BASE(TaskRemoveCallbackContext)
public:
    virtual ~TaskRemoveCallbackContext() = default;

    Task* mTask;
    void* mUserData;
};
KSYS_CHECK_SIZE_NX150(TaskRemoveCallbackContext, 0x18);

using TaskDelegate = sead::AnyDelegate1R<void*, bool>;
using TaskPostRunCallback = sead::IDelegate2<TaskPostRunResult*, const TaskPostRunContext&>;
using TaskRemoveCallback = sead::IDelegate1<const TaskRemoveCallbackContext&>;

class TaskDelegateSetter {
    SEAD_RTTI_BASE(TaskDelegateSetter)
public:
    TaskDelegateSetter();
    explicit TaskDelegateSetter(TaskDelegate* delegate) : TaskDelegateSetter() {
        setDelegate(delegate);
    }
    virtual ~TaskDelegateSetter();
    TaskDelegate* getDelegate() const { return mDelegate; }
    void setDelegate(TaskDelegate* delegate);

private:
    TaskDelegate* mDelegate = nullptr;
};
KSYS_CHECK_SIZE_NX150(TaskDelegateSetter, 0x10);

class TaskRequest {
    SEAD_RTTI_BASE(TaskRequest)
public:
    virtual ~TaskRequest() = default;

    bool mHasHandle;
    /// If true, request submissions will block until the request is processed.
    bool mSynchronous;
    u8 mLaneId;
    TaskThread* mThread;
    TaskQueueBase* mQueue;
    TaskDelegate* mDelegate;
    void* mUserData;
    TaskRemoveCallback* mRemoveCallback;
    TaskPostRunCallback* mPostRunCallback;
    sead::SafeString mName;
};
KSYS_CHECK_SIZE_NX150(TaskRequest, 0x50);

class Task {
    SEAD_RTTI_BASE(Task)
public:
    enum class Status {
        Uninitialized = 0,
        RemovedFromQueue = 1,
        Pushed = 2,
        Fetched = 3,
        PreFinishCallback = 4,
        RunFinished = 5,
        PostFinishCallback = 6,
        Finalized = 7,
    };

    explicit Task(sead::Heap* heap);
    Task(sead::Heap* heap, sead::IDisposer::HeapNullOption heap_null_option);
    virtual ~Task();

    bool setDelegate(const TaskDelegateSetter& setter);
    bool submitRequest(TaskRequest& request);
    bool canSubmitRequest() const;
    void processOnCurrentThreadDirectly(TaskThread* thread);

    void removeFromQueue();
    void removeFromQueue2();

    void cancel();
    bool wait();
    bool wait(const sead::TickSpan& span);

    Status getStatus() const { return mStatus; }
    bool isSuccess() const;
    bool isInactive() const;

    u8 getLaneId() const;
    void* getUserData() const;
    TaskQueueBase* getQueue() const { return mQueue; }

protected:
    friend class TaskQueueBase;
    friend class TaskThread;

    enum class Flag : u8 {
        DeleteDelegate = 0x1,
        DoNotDeleteDelegate = 0x2,
        NeedsToSignalEvent = 0x4,
        SynchronousRequest = 0x8,
        Cancelled = 0x10,
    };

    static size_t getListNodeOffset() { return offsetof(Task, mListNode); }

    virtual bool onSetDelegate_(const TaskDelegateSetter&) { return true; }
    virtual void prepare_(TaskRequest* request);
    virtual void run_();
    virtual void onRunFinished_() {}
    virtual void onFinish_() {}
    virtual void onPostFinish_() {}
    virtual void preRemove_() {}
    virtual void postRemove_() {}

    void setLaneId(u8 id);
    void setThread(TaskThread* thread);
    void setStatusPushed();
    void setStatusFetched();
    void run();
    void onRunFinished();
    void invokePostRunCallback(TaskPostRunResult* result);
    void finish();
    void onRemove();

    void finalize_();
    void deleteDelegate_();
    void invokeRemoveCallback_();

    void signalEvent() {
        if (!mFlags.isOn(Flag::NeedsToSignalEvent))
            return;

        mFlags.reset(Flag::Cancelled);
        mEvent.setSignal();
    }

    u8 mLaneId = 0;
    sead::TypedBitFlag<Flag> mFlags = Flag::DoNotDeleteDelegate;
    bool mDelegateResult = false;
    TaskDelegate* mDelegate = nullptr;
    void* mUserData = nullptr;
    TaskQueueBase* mQueue = nullptr;
    TaskThread* mThread = nullptr;
    TaskPostRunCallback* mPostRunCallback = nullptr;
    TaskRemoveCallback* mRemoveCallback = nullptr;
    Status mStatus = Status::Uninitialized;
    sead::ListNode mListNode;
    Event mEvent;
    sead::SafeString mName;
};
KSYS_CHECK_SIZE_NX150(Task, 0xa8);

inline void Task::prepare_(TaskRequest*) {}

}  // namespace ksys::util
