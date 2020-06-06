#ifndef UCI_QUEUE_H
#define UCI_QUEUE_H

#include <queue>
#include <vector>
#include <condition_variable>

typedef std::vector<std::string> uci_command;
typedef uci_command::iterator command_iter;

template<typename T>
class UCICommandQueue {
    std::queue<T> safe_queue;
    std::mutex mut;
    std::condition_variable cv;

    public:
        bool push(T elem) {
            std::unique_lock<std::mutex> lock(mut);
            safe_queue.push(elem);
            cv.notify_one();
            return true;
        }

        T pop() {
            // lock on the queue's mutex
            std::unique_lock<std::mutex> lock(mut);

            // block until queue is not empty, unlocking the queue mutex while blocked
            cv.wait(lock, [this]{return not safe_queue.empty();});

            T elem = safe_queue.front();
            safe_queue.pop();
            return elem;
        }

        bool empty() {
            return safe_queue.empty();
        }

        unsigned int size() {
            return safe_queue.size();
        }
};

#endif
