#include "Process.h"
#include "Task.h"
#include "UsableResource.h"
#include "ConsumableResource.h"
#include <iostream>

int main() {
    try {
        const auto compilationProcess = std::unique_ptr<Process>(
                new Process("CompileMain", "Compile main.cpp to main.exe",
                            { "CentralProcessingUnit", "Memory"}, 15));
        // Add resources to resource pool
        compilationProcess->addResource(
                std::unique_ptr<ConsumableResource>(new ConsumableResource("Memory", 4096)));
        compilationProcess->addResource(
                std::unique_ptr<UsableResource>(new UsableResource("CentralProcessingUnit", 3)));
        // Define compilation tasks
        compilationProcess->addTask(std::unique_ptr<Task>(new Task("ScanSourceCode", "Tokenize main.cpp",
                                                                   { "CentralProcessingUnit", "Memory"}, 2)));
        // Run successful compilation
        std::cout << "Starting compilation process..." << std::endl;
        compilationProcess->run();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
