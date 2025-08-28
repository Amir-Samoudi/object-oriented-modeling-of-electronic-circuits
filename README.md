# Object-Oriented Modeling of Electronic Circuits

This repository contains the assignments for the **"Object-Oriented Modeling of Electronic Circuits"** course.  
The projects focus on applying advanced, hardware-oriented programming concepts to **model and simulate electronic systems**.  
The coursework utilizes **C++-based languages like SystemC** for Register-Transfer Level (RTL) and Transaction level (TLM) modeling, and its derivative, **SystemC-AMS**, for analog and mixed-signal simulations.

---

## Topics Covered
- **C++ & SystemC**: Object-oriented modeling of digital components at the RT level  
- **SystemC-AMS**: Modeling and simulation of analog and mixed-signal systems  
- **Hardware Design Workflow**: Translating from Verilog netlists to C++ models and procedural simulation  

---

## Assignments

### Assignment 1: C++ Logic Modeling – Functional Model Extractor
**Goal**: Convert a gate-level Verilog netlist (composed of AND, OR, NOT gates) into an equivalent functional model using C++ expressions.  

**Description**:  
A C++ program was developed to parse a Verilog netlist and generate a functional Verilog description with `assign` statements.  
This **functional model extraction** simplifies the circuit representation and significantly speeds up simulation time.  

---

### Assignment 2 & 3: C++ Gate Modeling – Sequential Multiplier
**Goal**: Design, synthesize, and simulate a **4-bit sequential add-and-shift multiplier**.  

**Description**:  
- Designed the multiplier at the RTL in Verilog  
- Synthesized using **Yosys** to generate a gate-level netlist  
- Converted the netlist into a **procedural** C++ model for simulation  
- Developed a C++ program to correctly order gate instantiations for proper procedural simulation  

---

### Assignment 4: C++ & SystemC RTL Modeling – Selection Sorter
**Goal**: Design a circuit that sorts **256 16-bit words** using the selection sort algorithm.  

**Description**:  
The sorter was modeled in two implementations:  
1. Using a **C++ bus library** and applying procedural simulation
2. Using **SystemC**  
  
---

### Assignment 5 & 6: SystemC BFM/RTL Modeling – Pattern Finder Circuit
**Goal**: Implement a hardware module that searches for predefined patterns in an input image using a **convolutional architecture**.  

**Description**:  
- Designed in **SystemC** at both **Bus-Functional Model (BFM)** and **RTL** levels  
- Circuit features three **parallel convolutional blocks**, each with:  
  - A **3×3 kernel**  
  - **ReLU activation**  
  - **2×2 Max Pool** layer 

---
