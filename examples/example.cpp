int main()
{
    tree_t tree;
    char op;
    while (std::cin >> op && op != 'q')
    {
        int a;
        switch (op)
        {
            case '=':
                tree.print(std::cout);
                break;
            case '?':
                if (std::cin >> a)
                {
                    if (!tree.find(a))
                    {
                        std::cout << "Element is in tree";
                    }
                    else std::cout << "Element isn't in tree";
                }
                else
                {
                    std::cout << "An error has occured while reading input data" << std::endl;
                    exit(0);
                }
                break;
            case '+':
                if (std::cin >> a)
                {
                    tree.insert(a);
                    tree.print(std::cout);
                }
                else
                {
                    std::cout << "An error has occured while reading input data" << std::endl;
                    exit(0);
                }
                break;
        }
        return 0;
    }
}
