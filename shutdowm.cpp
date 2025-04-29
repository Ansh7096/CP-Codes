#include <cstdlib>  

int main() {
  
    #ifdef _WIN32
        system("shutdown /s /t 0"); 
    #elif __linux__
        system("shutdown now");    
    #elif __APPLE__
        system("sudo shutdown -h now"); 
    #else
        std::cout << "Shutdown command not supported on this OS.\n";
    #endif

    return 0;
}
