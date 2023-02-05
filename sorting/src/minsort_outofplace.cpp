#include <minsort_outofplace.hpp>

std::vector<int> minsort_outofplace(std::vector<int>& A) {

    std::vector<int> B(A.size());
    std::unordered_multiset<int> S(A.begin(), A.end());

    for (int i = 0; i < A.size(); i++) {
        int min = *(S.begin()); 
        for (auto itr = S.begin(); itr != S.end(); itr++) {
            if (*itr < min) {
                min = *itr;
            }
        }
        B[i] = min;
        S.erase(S.find(min));
    }

    return B;

}
