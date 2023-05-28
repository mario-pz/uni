#include <iostream>
#include <exception>

int main(){

   try {
      throw "το μισό αυτό το πράγμα";
   }
   catch (const char* e)
   {
      std::cout<< "Exception: " << e << std::endl;
   }
}
