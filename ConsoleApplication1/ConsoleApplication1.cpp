#include <iostream>
#include <cstdlib>

using namespace std;
const char* findFloat(const char* s, const char** e = NULL) {
    const char* p, * t = s;
    while (*s) {
        while (*s && !(*s >= '0' && *s <= '9'))
            ++s;

        p = s;
        while (*s >= '0' && *s <= '9')
            ++s;

        if (p == s)
            break;
        else if (*s == '.') {
            ++s;
            while (*s >= '0' && *s <= '9')
                ++s;
            if ((p > t) && (*(p - 1) == '-'))
                --p;

            if (e != NULL)
                *e = s;
            return p;
        }
    }
    return NULL;
}

int main(void) {
    const char* p = findFloat("++-dgss12.34.5+3f44f");
    //if (p != NULL)
    //    std::cout << atof(p) << std::endl;

    //if ((p = findFloat("+==-dhfy-13.hfjf")) != NULL)
    //    std::cout << atof(p) << std::endl;

    //найти все вещественные числа
    char s[] = "0.345 (389.5) bla-bla0.78,67,-5.123";

    cin >> s;

    const char* e = NULL;
    for (p = s; (p = findFloat(p, &e)) != NULL; p = e)
        std::cout << atof(p) << ' ';
    std::cin.get();
    return 0;
}