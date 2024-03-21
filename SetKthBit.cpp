 int setKthBit(int N, int K)
    {
        // Write Your Code here
        N=(N|(1<<K));
        return N;
    }