#ifndef TEMPLATE_H
#define TEMPLATE_H

template <class T1, class T2>
T1 frequent(T1 a[], T2 size){
    T1 diff[size] = {0};
    int counts[size] = {0};
    for (int i = 0; i < size; i++){
        if(diff[i]==a[i]){
            counts[i]++;
        }else if (diff[i]==0){//if you've reached an empty element, it means nothing matched
            diff[i]=a[i];
            counts[i] = 1;
        }
    }
    int max = 0;
    int index = 0;
    for (int i = 0; i < size; i++){
        if(counts[i]>max){
            max=counts[i];
            index = i;
        }
    }
    return diff[index];
}

#endif // TEMPLATE_H
