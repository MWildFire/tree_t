//
//  tree_t.hpp
//  tree_0.0.2
//
//  Created by Сурков Дмитрий Валерьевич on 09.05.2018.
//  Copyright © 2018 Сурков Дмитрий Валерьевич. All rights reserved.
//
#include <iostream>

template <class T>
class tree_t
{
private:
    struct node_t
    {
        node_t * left;
        node_t * right;
        T key;
        
        node_t()
        {
            left = nullptr;
            right = nullptr;
            key = 0;
        }
        
        ~node_t()
        {
            delete left;
            delete right;
        }
        
        void addingkey(T value)
        {
            if (key > value)
            {
                if (left == nullptr)
                {
                    left = new node_t();
                    left->key = value;
                }
                else left->addingelem(value);
            }
            else if (right == nullptr)
            {
                right = new node_t();
                right->key = value;
            }
            else right->addingelem(value);
            return;
        }
        
        bool findingkey(T value)
        {
            if (key == value)
            {
                return true;
            }
            if (key > value)
            {
                if (left != nullptr)
                {
                    return left->findingelem(value);
                }
                else return false;
            }
            if (key < value)
            {
                if (right != nullptr)
                {
                    return right->findingelem(value);
                }
                else return false;
            }
        }
        
        void print_tree(std::ostream & stream, T line = 0)
        {
            if (left != nullptr)
            {
                left->print_tree(stream, line + 4);
            }
            for (int i = 0; i < line + 4; i ++)
                stream << '-';
            stream << key << std::endl;
            if (right)
            {
                right-> print_tree(stream, line +4);
            }
        }
        
        bool delete_t(T value)
        {
            if (value > key)
            {
                if (right != nullptr)
                {
                    if (right -> key == value && right -> left == nullptr && right -> right == nullptr)
                    {
                        delete right;
                        right = nullptr;
                        return true;
                    }
                    else return right -> delete_t(value);
                }
            }
            if (value < key)
            {
                if (left != nullptr)
                {
                    if (left -> key == value && left -> left == nullptr && left -> right == nullptr)
                    {
                        delete left;
                        left = nullptr;
                        return true;
                    }
                    else return left -> delete_t(value);
                }
            }
            if (value == key)
            {
                if (right == nullptr && left != nullptr)
                {
                    key = left -> key;
                    node_t *temp = left;
                    right = left -> right;
                    left = left -> left;
                    temp -> left = nullptr;
                    temp -> right = nullptr;
                    delete temp;
                    return true;
                }
                
                if (right != nullptr && left == nullptr)
                {
                    key = right -> key;
                    node_t * temp = right;
                    right = right -> right;
                    left = right -> left;
                    temp -> left = nullptr;
                    temp -> right = nullptr;
                    delete temp;
                    return true;
                }
                
                if (right != nullptr && left != nullptr)
                {
                    node_t * min_temp = right;
                    if (min_temp -> left == nullptr)
                    {
                        key = min_temp -> key;
                        right = min_temp -> right;
                        min_temp -> right = nullptr;
                        min_temp -> left = nullptr;
                        delete min_temp;
                        return true;
                    }
                    while (min_temp -> left != nullptr)
                    {
                        min_temp = min_temp -> left;
                    }
                    key = min_temp -> key;
                    return right->delete_t(key);
                }
                return false;
            }
            return false;
        }
        
        auto operator==(node_t & other) const
        {
            if (right == nullptr && left == nullptr && key == other.key)
                return true;
            if (right == nullptr && left != nullptr && key == other.key && *(left) == *(other.left))
                return true;
            if (right != nullptr && left == nullptr && key == other.key && *(right) == *(other.right))
                return true;
            if (left != nullptr && right != nullptr && key == other.key && *(left) == *(other.left) && *(right) == *(other.right))
                return true;
            if ((left == nullptr && other.left != left) || (other.left == nullptr && left != other.left))
                return false;
            if ((right == nullptr && other.right != right) || (other.right == nullptr && right != other.right))
                return false;
            return false;
        }
    };
    
private:
    node_t * root_;
public:
    
    tree_t(std::initializer_list<T> keys)
    {
        root_ = nullptr;
        for (T i : keys)
        {
            this->insert(i);
        }
    }
    
    void insert(T key)
    {
        if (root_ == nullptr)
        {
            root_ = new node_t;
            root_->key = key;
            return;
        }
        else
        {
            root_->addingkey(key);
            return;
        }
    }
    
    bool find(T key) const
    {
        if (root_ != nullptr)
        {
            root_->findingkey(key);
        }
        return false;
    }
    
    void print(std::ostream & stream) const
    {
        if (root_ != nullptr)
        {
            root_->print_tree(stream, 0);
        }
        else std::cout << "ERROR! Tree is empty!" << std::endl;
        return;
    }
    
    bool remove (T key)
    {
        if ( root_ == nullptr)
        {
            std::cout << "ERROR! Tree doesn't exist";
            return false;
        }
        
        if (root_ ->left != nullptr || root_ -> right != nullptr)
        {
            return root_ -> delete_t(key);
            
        }
        if (root_ != nullptr && root_ -> left == nullptr && root_ -> right == nullptr)
        {
            delete root_;
            root_ = nullptr;
            return true;
        }
        return false;
    }
    
    auto operator==(tree_t const & other)
    {
        if (root_ == nullptr && other.root_ == nullptr)
        {
            return true;
        }
        if (root_ == nullptr || other.root_ == nullptr)
        {
            return false;
        }
        
        return *(root_ == other.root_);
    }
};








