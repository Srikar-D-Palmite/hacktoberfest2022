#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node * next;
};
typedef struct Node Node;
typedef Node* List;
//--------------

List makeList()
{
    Node* newNode_p = (Node*)malloc(sizeof(Node));

    newNode_p->val = -99999;
    newNode_p->next = NULL;
    return newNode_p;
}

//--------------

void append(List L, int elem)
{
    while(L->next != NULL)
    {
        L = L->next;
    }

    Node* newNode_p = (Node*)malloc(sizeof(Node));
    newNode_p->val = elem;
    newNode_p->next = NULL;

    L->next = newNode_p;

    return;
}

//--------------

int length(List L)
{    
    int res = 0;
    while(L->next != NULL){
        L = L->next;
        res += 1;
    }
    return res;
}

//--------------
void printList(List L)
{
    printf("[");
    while(L->next != NULL)
    {
        L = L->next;
        printf("%d, ", L->val);
    }
    printf("\b\b]\n");
}
//--------------

int removeElem(List L, int elem)
{    
    if((L->next)->val == elem){
        Node* currNode_p = L->next;
        L->next = currNode_p->next;
        free(currNode_p);
        return 0;
    }
    else
    {        
        Node* prevNode_p = L;
        Node* currNode_p = L->next;

        while(1==1)
        {        
            if(currNode_p->val == elem){
                prevNode_p->next = currNode_p->next;
                free(currNode_p);
                return 0;
            }
            prevNode_p = currNode_p;
            currNode_p = currNode_p->next;

            if(prevNode_p->next == NULL)
            {
                break;
            }
        }
        printf("the elem %d does not exist\n", elem);
        return -1;
    }

}

int clearList(List L)
{ 
    int n = length(L);
    List cpy = L;
    // for each node
    for(int i = n; i > 0; i--)
    {
        cpy = L;
        // go to the node
        while (cpy != NULL)
        {
            cpy = cpy->next;
        }
        // free it
        free(cpy);
    }
    return 0;
}

int find(List L, int pos)
{
    // go to node where element is
    for (int i = 0; i < pos; i++)
    {
        L = L->next;
    }
    // return the value there
    return L->val;
}

List reverse(List L)
{
    if (L->next == NULL)
    {
        return L;
    }
    List next = L->next->next;
    List curr = L->next;
    List prev= NULL;
    while (next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = curr;
    head->val = -99999;
    return head;
}

List mergeTwoLists(List l1, List l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    List solution = makeList();
    l1 = l1->next;
    l2 = l2->next;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            append(solution, l1->val);
            l1 = l1->next;
        }
        else
        {
            append(solution, l2->val);
            l2 = l2->next;
        }
    }
    while (l1 != NULL)
    {
        append(solution, l1->val);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        append(solution, l2->val);
        l2 = l2->next;
    }
    return solution;
}

int main(void)
{
    List L1 = makeList();
    append(L1, 3);
    append(L1, 8);
    append(L1, 4);
    append(L1, 9);
    L1 = reverse(L1);
    printList(L1);

    List L2 = makeList();
    append(L2, 10);
    L2 = reverse(L2);
    printList(L2);

    List L3 = makeList();
    append(L3, 11);
    append(L3, 5);
    L3 = reverse(L3);
    printList(L3);

    return 0;
}
// -Srikar D. Palmite