def mergesort(arr):
    if len(arr)<=1:
        return arr
    mid=len(arr)//2
    left=arr[:mid]
    right=arr[mid:]
    left=mergesort(left)
    right=mergesort(right)

    return merge_two_sortedlists(left,right)


def merge_two_sortedlists(a,b):
    sorted_list=[]
    i=j=0
    len_a=len(a)
    len_b=len(b)
    while i<len_a and j<len_b:
        if a[i]<b[j]:
            sorted_list.append(a[i])
            i+=1
        else:
            sorted_list.append(b[j])
            j+=1
    while i<len_a:
        sorted_list.append(a[i])
        i+=1
    while j<len_b:
        sorted_list.append(b[j])
        j+=1
    return sorted_list

if __name__ == '__main__':
    arr = [10,3,15,7,8,23,98,29]

    print(mergesort(arr))