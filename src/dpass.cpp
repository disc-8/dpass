/*>===========================================================================<l
 || 2024.03.17 ::               DPASS by ДiSC-8          :: About the project ||
 l>===========================================================================<l
 | This is a 'revival' of the zpass script we made a while ago, except it's    |
 | actually safe and portable this time.                                       |
 |>---------------------------------------------------------------------------<l
 | Jj"}px)sg#ipopa$uve"tkku esfe#vqmgxkhrg, edvv IJRH!                         |
 | cyv$ji"zqx"eppt$osep vcwcg${oxu"cqeh#lkke!l"rpho$|ovv"aruw                  |
 | ced}/1"fxht!igavd#oh JQCTUI0C[B                                             |
 | xi"kpq"prhpBOFseufe"YRW"rgkcrgogsu!ri eonthpw.#ts#hptg }oy$nmoi!lw"srykl!<G |
 |                                                                             |
 | j$ryu#RBUVKPO"irtr vhlu"ptsirdp. cog#ih ypxt#tkvk#atw"DERIW"xs$twhcm#mx     |
 | zsw$nd{!cvyfmn joufgiw"{owv"sklvhqmh0vkrgjqkwy1!mw'mp"hyrx$niww!li"zry$hopw |
 | siumtw.!cv"j!yipl#pwt#GSUCP"aprwnvt#rf"PATVKRN#jrwo!}qu2                    |
 |                                                  r--------------------------l
 | ulkw!dko)w"b!vhvedt. eq{."xjiv#c ybuqipg.        | s8. cc. 1/l. -fpr. fa♂q. |
 l>-------------------------------------------------^------------------------<*/
#define PROGNAME "dpass" 
#define VERSION "1.0.0"
// system includes
#include <stdlib.h>
#include <functional>
#include <string>
#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

// ojjlawdt.
#include "charlist.h"
#include "colors.h"

// cool array size macro
// https://www.ashn.dev/blog/2020-01-06-c-array-length.html
#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))

// dont change this
#define PASSLENGTH 60 //max site compatibility
#define ARGUMENTS 2 // username, website

void help();

int main(int argc,char* argv[]){
  if(argc!=ARGUMENTS+1){
    help();
    return 1;
  }
  string masterpass;

 // get input and hide with termios
  //set up termios
  termios reg;
  tcgetattr(STDIN_FILENO, &reg);
  termios hideinput = reg;
  hideinput.c_lflag &= ~ECHO;

 // read ♂Master♂ password
  tcsetattr(STDIN_FILENO, TCSANOW, &hideinput);
  printf(PP "Master Password:");
  cin >> masterpass;
  tcsetattr(STDIN_FILENO, TCSANOW, &reg);

 // initialize random
  string key=masterpass+argv[1]+argv[2]; // ^ARGUMENTS
  srand(std::hash<std::string>{}(key));
  printf("\n" PP "Master Hash: \e[32m%d\e[0m\n",std::hash<std::string>{}(masterpass));

 // da magiktrixx..
  printf("\e[32m");
  for(int i;i<PASSLENGTH;++i){
    printf("%s",charlist[rand()%ARRAY_LENGTH(charlist)]);
  }
  printf("\e[0m\n");
 }

void help(){
  printf(
 BGREEN PROGNAME CRESET " " BOLD VERSION CRESET " by " GREEN "ДiSC-8" CRESET "\n"
 "Database/file-less password \"manager\"\n"

 BOLD "Usage: " CRESET
 BLACK "$" CRESET " dpass " BLACK "[" GREEN "username" BLACK "] [" GREEN "website" BLACK "]" CRESET "\n");
}