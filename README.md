# 📊 Data Structures In Action
> *Clean implementations of fundamental data structures with testing and analysis for graduate studies*

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()
[![Code Style](https://img.shields.io/badge/code%20style-clean-orange.svg)]()

<br>

## 📖 Table of Contents

- [📌 Overview](#overview)
- [🗂️ Project Structure](#project-structure)
- [🚀 Implementations](#implementations)
- [🧪 Testing](#testing)
- [🎓 Research Perspective](#research_perspective)
- [🛠️ How to Run](#how-to-run)


---


<a id="overview"></a>
## Overview

This repository contains **clean, well-documented implementations** of essential data structures and algorithms, prepared with a **research perspective for graduate studies in Computer Science**.

**Why this repository stands out:**
- ✅ **Clean Code** principles applied throughout
- ✅ **Comprehensive comments** for educational clarity
- ✅ **Built-in test cases** for each implementation

---

<a id="project-structure"></a>
## 📁Project Structure

```

📁Data Structure   
│  
├── 📁Fundamentals  
│   ├── 📁ARRAY  
│   │   └── 📄DeleteArray.cpp  
│   ├── 📁BST  
│   │   └── 📄BST.cpp   
│   ├── 📁HASH  
│   │   └── 📄BuildHash.cpp  
│   ├── 📁HEAP  
│   │   └── 📄Max-Heap.cpp  
│   ├── 📁Linked List  
│   │   ├── 📄GroupInvert.cpp  
│   │   └── 📄IsPalindrome.cpp  
│   └── 📁QUEUE  
│       ├── 📄CircularQueue.cpp  
│       └── 📄SimpleQueue.cpp
│  
├── 📁Algorithms  
│   ├── 📁Array  
│   │   └── 📄LongestSubArray.cpp  
│   └── 📁Fibonacci  
│       └── 📄Fibonacci.cpp
│  
├── 📁 Applications  
│   └── 📁SimpleCalculator  
│       └── 📄SimpleCalculator.cpp
│  
├── 📄README.md
│  
└── 📄LICENSE  

```

---

<a id="implementations"></a>
## 🚀 Implementations

<br>

<h3>📁 Fundamentals - Data Structures</h3>

<table>
  <thead>
    <tr>
      <th>📂 Category</th>
      <th>📄 File</th>
      <th>🔧 Key Operations</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>📦 ARRAY</td>
      <td><code>DeleteArray.cpp</code></td>
      <td>Remove duplicates from sorted array (in-place)</td>
    </tr>
    <tr>
      <td>🌲 BST</td>
      <td><code>BST.cpp</code></td>
      <td>Insert, Delete, Search, Update (with successor)</td>
    </tr>
    <tr>
      <td>🔑 HASH</td>
      <td><code>BuildHash.cpp</code></td>
      <td>Insert, Find (chaining, custom hash for int/string)</td>
    </tr>
    <tr>
      <td>⛰️ HEAP</td>
      <td><code>Max-Heap.cpp</code></td>
      <td>Insert, DeleteMax, DeleteValue, Search, FindMin</td>
    </tr>
    <tr>
      <td rowspan="2">🔗 Linked List</td>
      <td><code>GroupInvert.cpp</code></td>
      <td>Reverse linked list in groups of K</td>
    </tr>
    <tr>
      <td><code>IsPalindrome.cpp</code></td>
      <td>Check palindrome (compares first with last)</td>
    </tr>
    <tr>
      <td rowspan="2">📋 QUEUE</td>
      <td><code>SimpleQueue.cpp</code></td>
      <td>Enqueue, Dequeue, Front, Size (Template-based)</td>
    </tr>
    <tr>
      <td><code>CircularQueue.cpp</code></td>
      <td>Enqueue, Dequeue, Front, Rear, isEmpty, isFull</td>
    </tr>
  </tbody>
</table>

<br>

<h3>⚡ Algorithms</h3>

<table>
  <thead>
    <tr>
      <th>📂 Category</th>
      <th>📄 File</th>
      <th>🔧 Algorithm Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>📐 Array</td>
      <td><code>LongestSubArray.cpp</code></td>
      <td>Longest subarray with sum ≤ K (sliding window for positives, brute force for negatives)</td>
    </tr>
    <tr>
      <td>🔢 Fibonacci</td>
      <td><code>Fibonacci.cpp</code></td>
      <td>Find Fibonacci numbers in array using perfect square property (5n²±4)</td>
    </tr>
  </tbody>
</table>

<br>

<h3>🧮 Applications</h3>

<table>
  <thead>
    <tr>
      <th>📂 Category</th>
      <th>📄 File</th>
      <th>🔧 Features</th>
      <th>🧠 Concepts Used</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>🧮 SimpleCalculator</td>
      <td><code>SimpleCalculator.cpp</code></td>
      <td>Infix expression evaluation with +, -, parentheses (supports multiple digits)</td>
      <td>Stack, Sign tracking, Parentheses handling</td>
    </tr>
  </tbody>
</table>

<br>

---

<a id="testing"></a>
## 🧪 Testing

**Every implementation includes built-in test cases** in its `main()` function.

### Example test output for BST:

```

=== Testing BST Implementation ===

Inserting elements: 50, 30, 70, 20, 40, 60, 80
Inorder traversal: 20 30 40 50 60 70 80

Testing Search:
Search 40: Found 
Search 100: Not found 

Testing Update (40 -> 45):
Update successful! 
Inorder traversal: 20 30 45 50 60 70 80

=== All tests completed successfully ===

```

---

<a id="research_perspective"></a>
## 🎓 Research Perspective

### Potential Research Directions:  

#### 1-Cache Performance Analysis  
- Compare BST vs Array-based structures with CPU cache profiling  

#### 2-Concurrent Data Structures  

- Implement fine-grained locking for BST  

- Compare with lock-free implementations  

#### 3-Memory-Efficient Structures  

- Reduce pointer overhead (store nodes in array)  

- Compression techniques for large datasets  

---

<a id="how-to-run"></a>
## 🛠️ How to Run

### Prerequisites  

- [C++17](https://www.geeksforgeeks.org/cpp/complete-guide-to-install-c17-in-windows/) compatible compiler  
- [VScode](https://code.visualstudio.com/download) or any other code editor (optional)

### Compile and Run

```
# Example for BST
cd Fundamentals/BST
g++ BST.cpp -o app
./app

# Example for Fibonacci
cd Algorithms/Fibonacci
g++ Fibonacci.cpp -o app
./app

```

---

## 🤝 Contributing

This repository is primarily for personal portfolio and graduate applications, but suggestions and discussions are welcome!


## 📧 Contact
For questions or discussions about this repository:

GitHub: [Pouya Maleki](https://github.com/Pouyamalek) 

Research Interests: Data structures, algorithms, performance optimization


## 📄 License

MIT License - feel free to use, learn, and improve!   

---


