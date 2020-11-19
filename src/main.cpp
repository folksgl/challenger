#include <thread>
#include "game_variables.hpp"
#include "uci.hpp"
#include "uci_command.hpp"

using namespace std;

bool G_debug;
Position* G_game_position;
SliderAttacks slider_attacks;
ThreadSafeQueue<UCICommand> command_queue;

int main()
{
    G_debug = false;

    std::thread command_producer(read_commands, std::ref(std::cin));
    std::thread command_consumer(process_commands);

    command_producer.join();
    command_consumer.join();

    return 0;
}
