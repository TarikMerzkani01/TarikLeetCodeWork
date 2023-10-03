char winnerOfGame(char * colors){
    char flags = 0; // 0b0000 seqAaddedAseqBaddedB
    int netA = 0;
    int i = 0;
    while(colors[i]) {
        if (colors[i] == 'A') {
            if (flags == 3) {   // if seqB and addedB
                netA += 1;      // cB -= 1; Adding back a count that was subtr
            }
            flags &= 12;        // seqB = addedB = False
            if (flags & 8) {    // if seqA  
                netA += 1;      
                flags |= 4;     // addedA = True;
            } else {
                flags |= 8;     // seqA = True;
            }
        } else {
            if (flags == 12) {  // if seqA and addedA
                netA -= 1;      // cA -= 1; 
            }
            flags &= 3;         // seqA = addedA = False
            if (flags & 2) {
                netA -= 1;      // cB += 1;
                flags |= 1;     // addedB = True;
            } else {
                flags |= 2;     // seqB = True;
            }
        }
        i++;
    }
    if (flags == 12) {
        netA -= 1;
    }
    if (flags == 3) {
        netA += 1;
    }  
    return netA > 0;
}