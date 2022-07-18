vector<int> Solution::primesum(int n) {
    vector<long long> primes;
    vector<bool> is_prime(n+1, true);

    for(long long i=2; i<=n; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(long long j = i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }

    int low = 0, high = primes.size()-1;
    while(low <= high){
        if(primes[low] + primes[high] == n)
            return {primes[low], primes[high]};
        else if(primes[low] + primes[high] < n)
            low++;
        else
            high--;
    }

    return {-1, -1};
}
