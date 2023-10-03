class Solution:
    
    def winnerOfGame(self, colors: str) -> bool:
        gamestate = "" + colors
        # mystr[:idx] substring left of letter
        # mystr[idx+1:] substring right of letter
        # mystr[:idx] + mystr[idx+1:]
        # Alice and Bob alternate removing pieces
        # Alice moves first
        # if a piece 'A' has both its neighbors both 'A', then Alice removes that piece A.
        # Similar rule for Bob but for B colored pieces
        # Cannot remove pieces from edge of the line
        # If a player can't do a remove on their turn, that player loses and other player wins
        # Assuming Alice and Bob play optimally, 
            #return true if Alice wins, or false if Bob wins
        

        # Plan:
        # Alice and Bob start at index 1 of string and end on lenString-2 (2ndtoLast)
        # One big for loop for a round of two turns, can end whichever turn

        # for: Alice turn, Bob Turn, loop
        curlen = len(gamestate)
        seqA = False
        seqB = False
        addedA = False
        addedB = False
        cA = 0  # Count of how many sandwiched As, min = 0
        cB = 0  # Similar count for B
        # if (cA == 0 or cA <= cB) B wins, else A wins
        # Deal with singular A and singular B
        for i in range(curlen):
            if (gamestate[i] == 'A'):
                if (seqA):
                    cA += 1
                    addedA = True
                seqA = True
                if (seqB and addedB):
                    cB -= 1
                seqB = False
                addedB = False
            else:
                if (seqB):
                    cB += 1
                    addedB = True
                seqB = True
                if (seqA and addedA):
                    cA -= 1
                seqA = False
                addedA = False
        if (seqA and addedA): # Last item
            cA -= 1
        if (seqB and addedB):
            cB -= 1
        return cA > cB            
            







        # Brute force
        # Remember for optimized, only need to traverse whole string once

        # while(True):
        #     # Alice Turn
        #     # Count three consecutive?
        #     aliceLoss = True
        #     bobLoss = True
        #     countA = 0
        #     curlen = len(gamestate)
        #     for a in range(curlen):
        #         if (gamestate[a] == 'A'):
        #             countA += 1
        #         else:
        #             countA = 0
        #         if (countA == 3):
        #             idx = a - 1
        #             gamestate = gamestate[:idx] + gamestate[idx+1:]
        #             aliceLoss = False
        #             break
        #     if(aliceLoss):
        #         break
        #     countB = 0
        #     curlen = len(gamestate)
        #     for b in range(curlen):
        #         if (gamestate[b] == 'B'):
        #             countB += 1
        #         else:
        #             countB = 0
        #         if (countB == 3):
        #             idx = b - 1
        #             gamestate = gamestate[:idx] + gamestate[idx+1:]
        #             bobLoss = False
        #             break
        #     if (bobLoss):
        #         break
        # return (not aliceLoss)


