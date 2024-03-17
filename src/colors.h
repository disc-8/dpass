#ifndef NOCOLOR
  #define BOLD   "\e[1m"
  #define GREEN  "\e[32m"
  #define BGREEN "\e[1;32m"
  #define BLACK  "\e[30m"
  #define CRESET "\e[0m"
  
  #define PP "["GREEN PROGNAME CRESET"] "
#else
  #define BOLD   
  #define GREEN  
  #define BGREEN 
  #define BLACK  
  #define CRESET 
 
  #define PP "[" PROGNAME "] "
#endif