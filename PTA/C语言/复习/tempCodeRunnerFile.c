for(int k = p; k <= r; k++){
        if(i < n1 && (j >= n2 || B1[i] <= B2[j])){
            A[k] = B1[i];
            i++;
        } else {
            A[k] = B2[j];
            j++;
        }
    