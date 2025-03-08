
#include <termios.h>
#include <unistd.h>


struct termios orig_termios; // To store original terminal settings

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios); // Restore the original terminal mode
}

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_termios); // Get original terminal attributes
    atexit(disableRawMode);                 // Ensure terminal is restored when the program exits

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG); // Disable echo, canonical mode, signal characters (Ctrl+C)
    raw.c_iflag &= ~(IXON);                         // Disable XON/XOFF flow control (Ctrl+S/Ctrl+Q)
    
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); // Apply raw mode settings
}

// Function to read a single character from the terminal in raw mode
int getch()
{
    char c;
    if (read(STDIN_FILENO, &c, 1) == -1) return -1;
    return c;
}