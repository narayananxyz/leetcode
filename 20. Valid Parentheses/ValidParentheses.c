#define STACK_TOP (5000)

typedef struct stck {
    char *data;
    int ptr;
} stack_t;

bool isValid(char * s){

    stack_t *mystack = (stack_t *)malloc(sizeof(stack_t));
    mystack->data = (char *)malloc((STACK_TOP) * sizeof(char));
    mystack->ptr = STACK_TOP;

    while (s && *s != '\0') {
        switch(*s) {
            case '(':
            case '[':
            case '{':
                mystack->ptr = mystack->ptr - 1;
                mystack->data[mystack->ptr] = *s;
                break;
            case ')':
                if((mystack->ptr != STACK_TOP) && (mystack->data[mystack->ptr]) == '(') {
                    mystack->ptr++;
                } else {
                    free(mystack->data);
                    free(mystack);
                    return false;
                }
                break;
            case ']':
                if((mystack->ptr != STACK_TOP) && (mystack->data[mystack->ptr]) == '[') {
                    mystack->ptr++;
                } else {
                    free(mystack->data);
                    free(mystack);
                    return false;
                }
                break;
            case '}':
                if((mystack->ptr != STACK_TOP) && (mystack->data[mystack->ptr]) == '{') {
                    mystack->ptr++;
                } else {
                    free(mystack->data);
                    free(mystack);
                    return false;
                }
                break;
        }

        s++;
    }

    if((mystack->ptr != STACK_TOP)) {
        free(mystack->data);
        free(mystack);
        return false;
    }

    free(mystack->data);
    free(mystack);

    return true;

}