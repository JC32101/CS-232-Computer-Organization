char password[8] = "secret";
int main() {
    char input[8];
    int i;
    printf("please enter your password\n");
    scanf("%s", input);

    for(i = 0; i < 8; i++){
      if((input[i] && password[i]) == 0){
        input[i];
        input[i] += 32;
      }
      else if(strcmp(input, password)==0){
          retun 0;
      }
      else{
        return -1;
      }
    }

    /*
    if(strcmp(input, password)==0) {
        return 0;
    } else {
        return -1;
    }
    */

}
