
#include <stdlib.h>
#include <stdio.h>

typedef struct ht_item {
    int key;
    int value;
    struct ht_item* left;
    struct ht_item* right;
} ht_item;

typedef struct {
    ht_item* root;
    int count;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* myhm = malloc(sizeof(MyHashMap));
    myhm->count = 0;    // count of items
    myhm->root = NULL;
    return myhm;
}

int helperPut(ht_item* item, int key, int value) {
    // Binary Search Tree
    if (key < item->key) {
        if (item->left == NULL) {
            ht_item* newitem = malloc(sizeof(ht_item));
            newitem->key = key;
            newitem->value = value;
            newitem->left = NULL;
            newitem->right = NULL;
            item->left = newitem;
            return 2;
        } else {
            helperPut(item->left, key, value);
        }
    } else if (key > item->key) {
        if (item->right == NULL) {
            ht_item* newitem = malloc(sizeof(ht_item));
            newitem->key = key;
            newitem->value = value;
            newitem->left = NULL;
            newitem->right = NULL;
            item->right = newitem;
            return 2;
        } else {
            helperPut(item->right, key, value);
        }
    } else {
        item->value = value;
        return 1;   // No new item added to hashmap
    }
    return 1;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    if (obj->root == NULL) { //empty tree
        ht_item* newitem = malloc(sizeof(ht_item));
        newitem->key = key;
        newitem->value = value;
        newitem->left = NULL;
        newitem->right = NULL;
        obj->root = newitem;
    } else {  //non-empty case
        if (helperPut(obj->root, key, value) == 2) {
            //success
            obj->count++;
        } 
    }
    return;
}


int helperGet(ht_item* item, int key) {
    if (item == NULL)
        return -1;
    if (key < item->key) 
        return helperGet(item->left, key); 
    if (key > item->key) 
        return  helperGet(item->right, key);
    return item->value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    if (obj->root == NULL) { //empty tree
        return -1;      // Not found
    } 
    return helperGet(obj->root, key);
}

ht_item* inorderSuccessorParent(ht_item* item) {
    // RETURNS the parent of the inordersuccessor of the node given
    // Assumes item is not null
    if (item->right == NULL) {
        return NULL;    // No successor case
    }
    ht_item* cur = item->right;
    ht_item* prev = item;
    while(cur->left != NULL) {
        prev = cur;
        cur = cur->left;
    }
    return prev;    // Can have returned just item
}

void rootReplace(ht_item* root) {
    ht_item* succParent = inorderSuccessorParent(cur);
    
}

void generalReplace(ht_item* prev) {
    // Case 1: No children
    // Case 2: At least one children
    // Case 3: Both Children
    ht_item* succParent = inorderSuccessorParent(cur);
    // This may have returned cur or something later.
    // returns NULL never in this case since we have both children
    // Successor is always left child of succParent or just cur
    ht_item* succ;
    if (succParent == cur) {
        succ = succParent->right;
    } else {
        succ = succParent->left;
    }
    cur->key = succ->key;
    cur->value = succ->value;
    // Succ may have right sub-tree
    if (succParent == cur) {
        cur->right = succ->right;
    } else {
        succParent->left = succ->right;
    }
    free(succ);
}

int helperRemove(MyHashMap* map, int key) {
    //
    if (map->root->key == key) {

    }
}

void myHashMapRemove(MyHashMap* obj, int key) {
    // Check if null first
    if (obj->root == NULL) {
        return; // Nothing to remove
    } else {
        if (helperRemove(obj, key) == 2) {
            //success
            obj->count--;
        } 
    }
    return;
}

void helperFree(ht_item* item) { // helperFree
    if (item == NULL) {
        return;
    }
    helperFree(item->left);
    helperFree(item->right);
    free(item);
}

void myHashMapFree(MyHashMap* obj) {
    // Check if null first
    if (obj == NULL) {
        return;
    }
    if (obj->root != NULL) {
        helperFree(obj->root);
    }
    free(obj);
    return;
}

int main() {
    MyHashMap* obj = myHashMapCreate();
    int key = 1;
    int value = 53;
    myHashMapPut(obj, key, value);
    key = 4;
    value = 12;
    myHashMapPut(obj, key, value);
    key = 3;
    value = 2;
    myHashMapPut(obj, key, value);
    int param_2 = myHashMapGet(obj, key);
    printf("%d", param_2);
    //myHashMapRemove(obj, key);
    myHashMapFree(obj);
}

// // Assume item is not null
//     ht_item* cur = map->root;
//     ht_item* prev = cur;
//     while(cur != NULL) {
//         prev = cur;
//         if (key < cur->key) {
//             if (cur->left == NULL) {
//                 // Could not find it
//                 return 1;
//             } else {
//                 // Traverse left
//                 cur = cur->left;
//             }
//         } else if (key > cur->key) {
//             if (cur->right == NULL) {
//                 return 1;
//             } else {
//                 cur = cur->right;
//             }
//         } else { // key == cur->key. Found in cur, Now Delete
//             // 1st case: No children
//             // 2nd case: One child
//             // 3rd case: Two child
//             char left = 0;  //cur is right child if 0
//             if (cur->key < prev->key) {
//                 //cur is left child
//                 left = 1;
//             }
//             // Check children
//             if (cur->right == NULL || cur->left == NULL) {
//                 //FREE cur AND REPLACE WITH LEFT SUBTREE
//                 ht_item* temp;
//                 if (cur->right == NULL) 
//                     temp = cur->left;
//                 else
//                     temp = cur->right;
//                 if (map->root == prev) { // if root
//                     free(cur);
//                     map->root = temp;   // can be null or left child
//                 } else {
//                     free(cur);
//                     if (left) {
//                         prev->left = temp;
//                     } else {
//                         prev->right = temp;
//                     }
//                 }
//             } 
//             else {
                
//                 ht_item* succParent = inorderSuccessorParent(cur);
//                 // This may have returned cur or something later.
//                 // returns NULL never in this case since we have both children
//                 // Successor is always left child of succParent or just cur
//                 ht_item* succ;
//                 if (succParent == cur) {
//                     succ = succParent->right;
//                 } else {
//                     succ = succParent->left;
//                 }
//                 cur->key = succ->key;
//                 cur->value = succ->value;
//                 // Succ may have right sub-tree
//                 if (succParent == cur) {
//                     cur->right = succ->right;
//                 } else {
//                     succParent->left = succ->right;
//                 }
//                 free(succ);
//             }
//             return 2;
//         }
//     }
//     return 1;