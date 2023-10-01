public class Stack {
    static readonly int MAX = 200000;
    int top;
    int[] stack = new int[MAX];

    public bool IsEmpty()
    {
        return (top < 0);
    }
    public Stack()
    {
        top = -1;
    }
    public bool Push(int data)
    {
        if (top >= MAX)
        {
            return false;
        }
        else
        {
            stack[++top] = data;
            return true;
        }
    }

    public int Pop()
    {
        if (top < 0)
        {
            return 0;
        }
        else
        {
            int value = stack[top--];
            return value;
        }
    }

    public int Peek()
    {
        if (top < 0)
        {
            return 0;
        }
        else 
        {
            int value = stack[top];
            return value;
        }
    }

    public void PrintStack()
    {
        if (top < 0)
        {
            Console.WriteLine("Stack Underflow");
            return;
        }
        else
        {
            Console.WriteLine("Items in the Stack are :");
            for (int i = top; i >= 0; i--)
            {
                Console.WriteLine(stack[i]);
            }
        
        }
    }
}


public class Solution {
    public bool Find132pattern(int[] nums) {
        if (nums.Length < 3) {
            return false;
        }
        //We obtain the best possible nums[i] for any nums[j]
        var mins = new int[nums.Length];
        mins[0] = nums[0];
        for (int i = 1; i < nums.Length; i++) {
            // we update mins[i] each iteration
            if (mins[i-1] > nums[i]) {
                mins[i] = nums[i];
            } else {
                mins[i] = mins[i-1];
            }            
        }
        // Now mins is initialized
        // Every minimum element found till the jth element
        // which acts as the nums[i] for the current nums[j]

        // We traverse backwards. To find a nums[k] that satisfies the 132 criteria
        // for a current nums[j], we know one of the conditions is that nums[k] must
        // be greater than nums[i].
        // In other words, we can say nums[k] must be greater than min[j] for a particular
        // nums[j] chosen.
        
        // Only thing that is left is to ensure nums[k] is lesser than nums[j]
        // TO KEEP TRACK of these potential nums[k] values for a particular
        // nums[i], nums[j] considered currently, we maintain a stack
        // on which these potential nums[k]'s satisfying the 132 criteria lie in
        // a descending order (minimum element on the top).
        Stack mystack = new Stack();

        // Assuming stack is sorted, let's say we are at jth element.
        // If nums[j] > mins[j], then we pop from stack until we find
        // and element stack[top] such that stack[top] > mins[j]
        // If not, we continue to (j-1)th element and stack remains sorted.

        // After popping is done, we're sure that all the elements pending on
        // the stack are greater than nums[i], and are thus the potential candidates
        
        for (int j = nums.Length-1; j > -1; j--) {
            if (nums[j] <= mins[j])
                continue;
            while (!mystack.IsEmpty() && mystack.Peek() <= mins[j]) {
                mystack.Pop();
            }
            if (!mystack.IsEmpty() && mystack.Peek() < nums[j]) {
                return true;
            }
            mystack.Push(nums[j]);
        }
        // Monotonic Stack (strictly increasing list)

        return false;
    }
}