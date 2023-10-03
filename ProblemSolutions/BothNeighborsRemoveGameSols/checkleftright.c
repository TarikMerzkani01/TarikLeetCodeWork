
char winnerOfGame(char * colors){
    int netA = 0;
    int i = 1;
    while(colors[i]) {
        if (colors[i - 1] == colors[i] && colors[i] == colors[i+1]) {
            if (colors[i] == 'A') {
                netA += 1;
            } else {
                netA -= 1;
            }
        }
        i++;
    }
    return netA > 0;
}