# Network Topology Using NS-3

This repository contains implementations of common network topologies using the **NS-3 network simulator**.  
Each topology is implemented in C++ and visualized using **NetAnim**.

The project is intended for **computer networks labs**, **academic reference**, and **learning NS-3 basics**.

---

## Topologies Implemented

### 1. Tree Topology
A hierarchical structure where nodes are connected in parent–child relationships.  
Used in organizational networks and routing hierarchies.

**Characteristics:**
- No loops
- Scalable structure
- Failure at upper levels affects child nodes

---

### 2. Bus Topology
All nodes are connected to a single shared communication line.

**Characteristics:**
- Simple and cost-effective
- Shared bandwidth
- Performance degrades with more nodes

---

### 3. Star Topology
All nodes are connected to a central hub or node.

**Characteristics:**
- Easy to manage
- Central node failure affects the entire network
- Widely used in LANs

---

### 4. Mesh Topology
Each node is connected to every other node.

**Characteristics:**
- High reliability
- Multiple paths between nodes
- Expensive and complex to implement

---

### 5. Ring Topology
Nodes are connected in a circular fashion where each node has exactly two neighbors.

**Characteristics:**
- Data flows in a ring
- Equal access for all nodes
- Failure of one link can break the ring

---

## Tools & Technologies Used

- NS-3
- C++
- NetAnim
- Linux / WSL

---

## How to Run

1. Place the `.cc` file inside the `scratch/` directory of NS-3.
2. Build NS-3:
   ```bash
   ./waf build
