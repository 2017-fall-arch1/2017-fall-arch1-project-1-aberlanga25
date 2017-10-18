

struct bst * newNode(int num, const char * info);

struct bst * insertN(struct bst * root, int num, const char * info);

struct bst * searchN(struct bst * leftL);

struct bst * deleteN(struct bst * root, const char * name);

void traverse(struct bst * root);

void readFile();

void writeFile(struct bst *root);



