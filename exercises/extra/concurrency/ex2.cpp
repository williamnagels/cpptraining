#include <global.h>

namespace
{

struct WorkQueue
{
    //start the worker thread in the constructor
    WorkQueue(){
    }

    //destructor is OK
    ~WorkQueue(){
        stop();
    }
    bool push_task(std::function<void()> functor)
    {
        //create a std::packaged_task from the functor,
        //does it make sense to change functor to r-value reference parameter?
        //push the task on the queue
        //wake up the worker queue
        //return true if the queue is still accepting work, otherwise return false
        return true;
    }
    void loop()
    {
        while (!m_worker.get_stop_token().stop_requested()) 
        {
            //wake up if stop requested or work in queue
            //pop work item from queue, do the task, go back to sleep
        }
        //empty all remaining work items, keep lock active
        std::unique_lock<std::mutex> lock(m_mutex);
        std::cout << "emptying queue"<<std::endl;
        //do all work items stop
    }

    void stop()
    {
        /*
            Implement stop
            request a stop of the worker thread it's token
            wake the thread up if it is sleeping
            join the thread
        */
    }

private:
    std::vector<std::packaged_task<void()>> m_workToDo;
    std::condition_variable m_wakeUpWorkerSignal;
    std::jthread m_worker;
    std::mutex m_mutex;
};

// Debug interface thread function
void debugThread(WorkQueue& queue) {
    std::cout << "debug thread-->"<<std::this_thread::get_id() << std::endl;
    while (true) {
        if(!queue.push_task([]() {
            std::cout<< "worker thread-->"<< std::this_thread::get_id() << std::endl;
        })){
            break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// Uncomment the lines below, make sure the debug thread stops when it can no longer
// push work items on the work queue.
// When looking at the print out of the thread_ids, do they make sense?
void test_1()
{
    WorkQueue queue;
    std::cout <<"main thread-->"<<std::this_thread::get_id() << std::endl;
    /*std::jthread debug(debugThread, std::ref(queue));
    std::this_thread::sleep_for(std::chrono::seconds(6));
    queue.stop();
    debug.join();*/
}
}
 
void conc_ex2()
{     
    test_1();
}
