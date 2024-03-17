#ifndef NOCOLOR
  #define BOLD   "\e[1m"
  #define GREEN  "\e[32m"
  #define BGREEN "\e[1;32m"
  #define BLACK  "\e[90m"
  #define CRESET "\e[0m"
  
  #define PP "["GREEN PROGNAME CRESET"] "

char* hashchar[]={
 "\e[41m  ","\e[42m  ","\e[43m  ","\e[44m  ","\e[45m  ","\e[46m  "
};

#else
  #define BOLD   
  #define GREEN  
  #define BGREEN 
  #define BLACK  
  #define CRESET 
 
  #define PP "[" PROGNAME "] "

char* hashchar[]={
 "-","X","0","|","\\","/"
};

#endif