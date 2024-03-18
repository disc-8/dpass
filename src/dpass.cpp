/*>===========================================================================<l
 || 2024.03.17 ::               DPASS by ДiSC-8          :: About the project ||
 l>===========================================================================<l
 | File-less password generator and "manager"                                  |
 |>---------------------------------------------------------------------------<l
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
 l>---------------------------,---------------------^-------------------------<l
 | ╔═╗┬ ┬┌─┐┌┐┌┌─┐┌─┐┬  ┌─┐┌─┐ l
 | ║  ├─┤├─┤││││ ┬├┤ │  │ ││ ┬ |
 | ╚═╝┴ ┴┴ ┴┘└┘└─┘└─┘┴─┘└─┘└─┘ |
 ^----------------------------^*-----------------------------------------------<
-> 1.2.1_00 <- :: 2024.III.18 :: Fix a SERIOUS issue
     - A lot of websites, and sometimes even terminal emulators didn't play well
       with the obscure unicode charlist, so I replaced it with a more standard
       extended-extended ASCII one.
     - Also, new versioning system
>------------------------------------------------------------------------------<
   1.1.1_00 :: 2024.III.17 :: Quality of Life
     - Added argument $3 as password length
     - Replaced master password hash with a checksum display
     - Compile script now passes arguments to C++ compiler
   1.1.1_01
     - Fixed checksum displaying incorrectly
>------------------------------------------------------------------------------<
   1.0.1_00 :: 2024.III.17 :: Hotfix
     - Fixed broken -DNOCOLOR
>------------------------------------------------------------------------------<
   1.0.0_00 :: 2024.III.17 :: RELEASE
     - Released
>-----------------------------------------------------------------------------*/
 
#define PROGNAME "dpass"

// ALGORITHM.QOL.BUGFIX 
#define VERSION "1.2.1_00"

// system includes
#include <stdlib.h>
#include <functional>
#include <string>
#include <iostream>

// unix libs
#include <termios.h>
#include <unistd.h>

using namespace std;

// ojjlawdt.
#include "charlist.h"
#include "colors.h"
#include "core-config.h"

// cool array size macro
// https://www.ashn.dev/blog/2020-01-06-c-array-length.html
#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))

void help(){
  printf(
 BGREEN PROGNAME CRESET " " BOLD VERSION CRESET " by " GREEN "ДiSC-8" CRESET "\n"
 "Database/file-less password \"manager\"\n"

 BOLD "Usage: " CRESET
 BLACK "\n\t$" CRESET " dpass " BLACK "[" GREEN "username" BLACK "] [" GREEN "website" BLACK "]" BLACK " [" CRESET "optional: " GREEN "password length" BLACK "]" CRESET "\n"
 BOLD "Default password length: " CRESET GREEN "%d\n",DEFPASSLENGTH);
}

int main(int argc,char* argv[]){
  if(argc<ARGS+1){
    help();
    return 1;
  }
  int length;
  if(argc!=ARGS+2){
    length=DEFPASSLENGTH;
  }else{
    length=atoi(argv[3]);
  }

  string masterpass;

 //set up termios, hide input
  termios reg;
  tcgetattr(STDIN_FILENO, &reg);
  termios hideinput = reg;
  hideinput.c_lflag &= ~ECHO;

 // read ♂Master♂ password
  tcsetattr(STDIN_FILENO, TCSANOW, &hideinput);
  printf(PP "Master Password:");
  cin >> masterpass;
  tcsetattr(STDIN_FILENO, TCSANOW, &reg);

 // initialize random seed
  string key=masterpass+argv[1]+argv[2]; // ^ARGUMENTS
 // so you can see typos
  srand(std::hash<std::string>{}(masterpass));
  printf("\n" PP "Checksum: " GREEN);
  for(int i;i<8;++i) printf("%s",hashchar[rand()%ARRAY_LENGTH(hashchar)]);
  printf(CRESET "\n");
  
 // da magiktrixx..
  srand(std::hash<std::string>{}(key)); 
  for(int i;i<length;++i) \
    printf("%s",charlist[rand()%ARRAY_LENGTH(charlist)]);
  printf("\e[0m\n");
 }
