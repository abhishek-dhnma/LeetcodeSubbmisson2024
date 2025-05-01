const int N=256, mask=255, bshift=8;
int freq[N];
void radix_sort(int* nums, int n) {
    int* output = (int*)alloca(n * sizeof(int));  // buffer
    unsigned M=*max_element(nums, nums+n);
    const int Mround = max(1, int(31-countl_zero(M)+bshift)/bshift);
    int* in=nums;
    int* out=output;
    bool swapped=0;

    for (int round=0; round<Mround; round++) {
        const int shift=round*bshift;
        memset(freq, 0, sizeof(freq));

        for (int i = 0; i < n; i++)
            freq[(in[i] >> shift) & mask]++;

        partial_sum(freq, freq+N, freq);

        for (int i = n - 1; i >= 0; i--) {
            int val = in[i];
            int x = (val >> shift) & mask;
            out[--freq[x]] = val;
        }

        swap(in, out);
        swapped = !swapped;
    }

    // If needed, copy back
    if (swapped)
        memcpy(nums, in, n * sizeof(int));
}

int q[50000], front=0, back=0;
class Solution {
public:
    int n, m, strength;
    bool doable(int* T, int* W, int k, int pills){
        int t_idx=0;
        front=back=0;// reset for the pointers for q
        for (int i=m-k; i<m; i++){
            int ws=W[i];
            for(; t_idx<k && T[t_idx]<=ws+strength; t_idx++)
                q[back++]=T[t_idx];
            
            if (front==back) return 0;
            if (q[front]<=ws) front++;//no need for pill for easiest task
            else{
                if (pills==0) return 0;
                pills--;
                back--; //take a pill for hardest task
            }
        }
        return 1;

    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        n=tasks.size(), m=workers.size();
        this->strength=strength;
        int* T=tasks.data(), *W=workers.data();
        radix_sort(T, n);
        radix_sort(W, m);

        int l=0, r=min(n, m);

        while (l<r) {
            int mid=(l+r+1)/2;
            if (doable(T, W, mid, pills))
                l=mid;
            else
                r=mid-1;
        }
        return l;
    }
};