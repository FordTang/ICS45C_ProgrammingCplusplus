//Ford Tang
//46564602
//ICS 45C
//Project 3

#include "HashMap.hpp"

namespace
{
    // Function that produces a hash from a string.  Used in tandem with
    // HashFunction to create hash for a word.
    unsigned int hash(const std::string& word)
    {
        // using multiplicative hash
        unsigned int result = 0;
        unsigned int multiplier = 31;
        unsigned int wordSize = word.size();
        for (unsigned int i = 0; i < wordSize; ++i)
            result = multiplier * result + word[i];
        
        //std::cout << "from hash: " << result << std::endl;
        return result;
    }
}

HashMap::HashMap()
    : hasher{hash}, bucketSize{initialBucketCount}, buckets{new Node*[initialBucketCount]}
{
    //std::cout << "default constructor" << std::endl;
    this->nullBuckets();
}

HashMap::HashMap(HashFunction hasher)
    : hasher{hasher}, bucketSize{initialBucketCount}, buckets{new Node*[initialBucketCount]}
{
    //std::cout << "hasher constructor" << std::endl;
    this->nullBuckets();
}

HashMap::HashMap(const HashMap& hm)
    :hasher{hm.hasher}, bucketSize{hm.bucketSize}, buckets{new Node*[hm.bucketSize]}
{
    //std::cout << "copy constructor" << std::endl;
    this->bucketArrayCopy(hm.buckets, hm.bucketSize);
}

HashMap::~HashMap()
{   
    //std::cout << "destructor" << std::endl;
    this->deleteBuckets();
}

HashMap& HashMap::operator=(const HashMap& hm)
{
    if (this != &hm)
    {
        //std::cout << "assignment overloader" << std::endl;
        //std::cout << "ao, size = " << bucketSize << std::endl;
        this->deleteBuckets();
        hasher = hm.hasher;
        bucketSize = hm.bucketSize; 
        buckets = new Node*[hm.bucketSize];
        this->bucketArrayCopy(hm.buckets, hm.bucketSize);
    }
    return *this;
}

void HashMap::add(const std::string& key, const std::string& value)
{
    if (this->contains(key))
        return;
    
    this->addNode(key, value);
    
    if (this->loadFactor() > 0.8)
    {   
        //std::cout << "add: new bucket" << std::endl;
        unsigned int oldSize = bucketSize;
        Node** oldBucket = buckets;
        bucketSize = bucketSize * 2 + 1;
        buckets = new Node*[bucketSize];
        this->nullBuckets();

        for (unsigned int i = 0; i < oldSize; ++i)
        {
            Node* check = oldBucket[i];
            while (check != nullptr)
            {
                this->addNode(check->key, check->value);
                check = check->next;
            }
        }
        
        //std::cout << "add: finish adding nodes" << std::endl;
            
        for (unsigned int i = 0; i < oldSize; ++i)
        {
            if (oldBucket[i] != nullptr)
                this->deleteNode(oldBucket[i]);
        }

        //std::cout << "add: deleted old nodes" << std::endl;

        delete[] oldBucket;

        //std::cout << "add: deleted old bucket" << std::endl;
    }
}

void HashMap::remove(const std::string& key)
{
    if (!(this->contains(key)))
        return;
    unsigned int index = hasher(key) % bucketSize;
    Node* prev = buckets[index];
    Node* current = prev->next;

    if (prev->key == key)
    {   
        buckets[index] = current;
        delete prev;
    }

    else
    {
        while (current->key != key)
        {
            prev = current;
            current = prev->next;
        }

        prev->next = current->next;
        delete current;
    }
}

bool HashMap::contains(const std::string& key) const
{
    unsigned int index = hasher(key) % bucketSize;
    //std::cout << "contains: index " << index << std::endl;
    //std::cout << "contains: bucket[" << index << "].next = " << buckets[index].next << std::endl;
    Node* check = buckets[index];
    //std::cout << "contains: check = " << check << std::endl;
    while (check != nullptr)
    {
        if (check->key == key)
        {
            //std::cout << "contains: found" << std::endl;
            return true;
        }
        check = check->next;
    }
    //std::cout << "contains: not found" << std::endl;
    return false;
}

std::string HashMap::value(const std::string& key) const
{
    if (!(this->contains(key)))
        return "";
    unsigned int index = hasher(key) % bucketSize;
    Node* check = buckets[index];
    while (check->key != key)
        check = check->next;
    return check->value;        
}

unsigned int HashMap::size() const
{
    //std::cout << "size" << std::endl;
    unsigned int result = 0;
    //std::cout << "size: bucketSize = " << bucketSize << std::endl;
    for (unsigned int i = 0; i < bucketSize; ++i)
    {
        if (buckets[i] != nullptr)
        {
            //std::cout << "size: " << i << " not null" << std::endl;
            result += this->countNode(buckets[i]);
        }
    }

    return result;
}

unsigned int HashMap::bucketCount() const
{
    unsigned int result = 0;
    for (unsigned int i = 0; i < bucketSize; ++i)
    {
        if (buckets[i] != nullptr)
            result++;
    }

    return result;
}

double HashMap::loadFactor() const
{
   return (double)this->size()/bucketSize;    
}

unsigned int HashMap::maxBucketSize() const
{
    unsigned int result = 0;
    for (unsigned int i = 0; i < bucketSize; ++i)
    {
        if (buckets[i] != nullptr)
        {
            unsigned int count = this->countNode(buckets[i]);
            if (count > result)
                result = count;
        }
    }

    return result;
}

void HashMap::clearBucket()
{
    this->deleteBuckets();
    buckets = new Node*[bucketSize];
    this->nullBuckets();
}


//Private Functions

void HashMap::nullBuckets()
    {
        for (unsigned int i = 0; i < bucketSize; ++i)
            buckets[i] = nullptr;
    }

void HashMap::bucketArrayCopy(Node** source, unsigned int size)
{
    this->nullBuckets();
    for (unsigned int i = 0; i < bucketSize; ++i)
    {
        if (source[i] != nullptr)
        {
            Node* copy = source[i];
            buckets[i] = new Node{copy->key, copy->value, nullptr};
            Node* destination = buckets[i];
            copy = copy->next;
            while (copy != nullptr)
            {
                destination->next = new Node{copy->key, copy->value, nullptr};
                destination = destination->next;
                copy = copy->next;
            }
        }
    }
}

// Function deletes a Node link list from memory.
void HashMap::deleteNode(Node* source)
{
    //std::cout << "deleteNode: start" << std::endl;
    if (source->next != nullptr)
    {   
        //std::cout << "deleteNode: delete next" << std::endl;
        this->deleteNode(source->next);
    }
    
    //std::cout << "deleteNode: delete self" << std::endl;
    delete source;
}

// Function deletes an array of Node link list from memory.
void HashMap::deleteBuckets()
{
    //std::cout << "deleteBuckets" << std::endl;
    for (unsigned int i = 0; i < bucketSize; ++i)
    {
        //std::cout << "deleteBuckets, i = " << i << std::endl;
        if (buckets[i] != nullptr)
        {   
            //std::cout << "deleteBuckets deleting " << i << std::endl;
            this->deleteNode(buckets[i]);
        }
    }

    delete[] buckets;
}

unsigned int HashMap::countNode(const Node* source) const
{
    unsigned int count = 1;
    if (source->next != nullptr)
        count += this->countNode(source->next);
    
    return count;
}

unsigned int HashMap::countBuckets()
{
    unsigned int count = 0;
    for (unsigned int i = 0; i < bucketSize; ++i)
    {
        if (buckets[i] != nullptr)
            count += this->countNode(buckets[i]);
    }

    return count;
}

void HashMap::addNode(const std::string& key, const std::string& value)
{    
    unsigned int index = hasher(key) % bucketSize;
    if (buckets[index] == nullptr)
        buckets[index] = new Node{key, value, nullptr};
    else
    {
        Node* check = buckets[index];
        while (check->next != nullptr)
            check = check->next;
        check->next = new Node{key, value, nullptr};
    }
}
