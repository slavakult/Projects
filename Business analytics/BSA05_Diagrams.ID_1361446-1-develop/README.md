# Modelings and diagrams

Summary:
You will be introduced to the concept of requirements modeling, basic models and representations, learn how to build a data flow diagram, a swimlane diagram, and a state diagram, how to use decision tables.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Preamble](#11)
2. [Chapter II](#chapter-ii) \
   2.1. [General Rules](#21)
3. [Chapter III](#chapter-iii) \
   3.1. [Models and Requirements Modeling](#31) \
   3.2. [Data Flow Diagram](#32) \
   3.3. [Swimlane Diagram](#33) \
   3.4. [Swimlane Diagram Extension](#34) \
   3.5. [State Diagram](#35)
4. [Chapter IV](#chapter-iv) \
   4.1. [Task 1. Haircut Appointement](#41) \
   4.2. [Task 2. Delivery of Orders](#42)
5. [Chapter V](#chapter-v) \
   5.1. [Exercise 00 — Building DFD, Level 0](#51) \
   5.2. [Exercise 01 — Building a Swimlane Diagram](#52) \
   5.3. [Exercise 02 — Extending the Swimlane Diagram](#53) \
   5.4. [Exercise 03 — State Diagram](#54) \
   5.5. [Exercise 04 — State Table](#55)

## Chapter I <div id="chapter-i"></div>

![](misc/images/Illustration_05.jpg)

### Preamble <div id="11"></div>

The first module introduced you to the basic concepts that IT analysts work with, such as stakeholders, requirements, requirements classification, and the concept of domain. 

In this module, you will learn techniques that allow analysts to describe requirements so that they can be understood more quickly, both by the system builders and by others. Requirements are presented in a variety of ways, including graphical diagrams, tables, and textual descriptions. 

In this project, you will learn about diagrams, their purpose and how to create a data flow and swimlane diagram, a state diagram and a state table.

### Literature

1. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition, amplified. 
2. Martin Fowler, Kendall Scott "UML Distilled: A Brief Guide to the Standard Object Modeling Language (2nd Edition)".
3. Craig Larman "Applying UML and Design Patterns — An Introduction to Object-Oriented Analysis".
4. BABOK v3 "A Guide to the Business Analysis Body of Knowledge" IIBA.
5. Dean Leffingwell, Don Widrig "Managing Software Requirements".

## Chapter II <div id="chapter-ii"></div>

### General Rules <div id="21"></div>

1. Along the way, you may feel a sense of uncertainty and a severe lack of information: that's OK. Remember, the information in the repository and on Google is always with you. So are your peers and Rocket.Chat. Communicate. Search. Use common sense. Don't be afraid to make mistakes.
2. Pay attention to sources of information. Check. Think. Analyse. Compare. 
3. Look at the text of each assignment. Read it several times. 
4. Read the examples carefully. There may be something in them that is not explicitly stated in the task itself.
5. You may find inconsistencies where something new in the terms of the task or examples conflicts with something you already know. If you come across such an inconsistency, try to work it out. If not, write it down as an open question and find out as you work. Do not leave open questions unanswered. 
6. If a task seems confusing or impossible, it only seems that way. Try to break it down. It is likely that some parts will become clear. 
7. There will be several tasks. Those marked with an asterisk (\*) are for the more meticulous students. These tasks are more difficult and are not compulsory. But doing them will give you extra experience and knowledge.
8. Don't try to fool the system or the people around you. You will fool yourself first.
9. Got a question? Ask your neighbour to the right. If that doesn't help, ask your neighbour on the left.
10. When you use help, you should always understand why and how. Otherwise the help is useless.
11. Always push only to the develop branch! The master branch will be ignored. Work in the src directory.
12. There should be no files in your directory other than those specified in the tasks.

## Chapter III <div id="chapter-iii"></div>

<p>“All models are wrong, some are useful.”</p>
<p>George Box</p>

### 1. Models and Requirements Modeling <div id="31"></div>

The history of successful IT projects (and not only IT projects) shows that presenting project requirements in one form does not give a complete picture (Alan Davis). It is necessary to provide not only a textual description of the current state and functional requirements, but also a graphical representation (diagrams of various kinds), tabular (for example, the state of various artifacts depending on conditions), prototypes of the user interface, reports, etc. Each of these representations shows the requirements in a separate section and fully covers this section. And comparing different representations allows to find inconsistencies, omissions and errors. Therefore, it is necessary to view the planned system in different models. 

A **Model** is a simplified description of reality that allows an object to be studied or processed, containing the essential properties of the object. A model is always simpler than a system and emphasizes one or more aspects of the system:

| Artifact                          | Models                                      | Components (aspects) of models     |
| --------------------------------- | ------------------------------------------- | ---------------------------------- |
| People, organizations, IT systems | Context diagram,     Data flow diagram       | External systems, external objects |
|                                   | Use case diagrams                           | Actors                             |
|                                   | ER diagram                                  | Entities or their attributes       |
|                                   | Swimlane diagram                            | Lanes                              |
|                                   | State & Transition diagram, table of states | Objects with states                |
| Transmitted and stored data       | Context diagram,     Data flow diagram       | Data flows and data stores         |
|                                   | ER diagram                                  | Entities or their attributes       |
|                                   | Swimlane diagram                            | Lanes                              |

The strictness of the application of notation in modeling is determined by the agreement within the team, depending on the purposes for which we build models, the purpose of the diagram, the level of participants, those who will read, comment on the diagram. It is acceptable to draw a simpler diagram for discussion with the customer than for application within the team. It is important that the team agrees and it is important to fulfill these agreements.

A more complete list of artifacts related to models and their components is given in Chapter 12 К. Wiegers "Software Requirements" 3rd edition, Table.12-1. The principles of selection of the most suitable models are summarized in Table 12-2.

We consider several visual representation models, which represent the system in one way or another:

- Data flow diagram;
- Swimlane diagram;
- State diagram (or state table);
- Business process diagram in BPMN notation;
- and you've already seen the context diagram (Module 1), which is a simplified data flow diagram.

It should be understood that diagrams can show both the current As-Is state for requirements identification (problem domain in requirements engineering terminology) and the future, projected To-Be state (solution domain). When creating a diagram, you should always understand which domain what you are creating relates to.

Therefore, before starting the diagram, it is necessary to define the following:

1. Purpose of the diagram;
2. Area of consideration: As-Is (problem area) or To-Be (solution area);
3. Method (diagram type).

### 2. Data Flow Diagram <div id="32"></div>

A data flow diagram (DFD) provides a view of how data moves within the system and between the system and the outside world, reflecting the stores and flows of data and materials (technically, information about materials, i.e., also data flows) that the system manages. The movement of data and materials between the external environment and the system (the system as a black box) is a context diagram, an extreme case of a data flow diagram. In addition, a more detailed data flow diagram can be built during the development process, showing the flows between processes or subsystems within the system, among themselves, and with external systems. A data flow diagram can be created for level 0 and deeper, decomposing flows and actions. The level 0 data flow diagram corresponds to the context diagram, but with an extension to functions within the system.

A DFD diagram can show the people or organizations that are the initiators of the data transfer or the recipients of the data. These are our stakeholders. That is, the data flow diagram should correlate with the stakeholder directory and with the onion diagram — we should check these correspondences and, if necessary, eliminate inconsistencies. But the diagram does not show the sequence of processes and activities. Do not try to show the sequence of processes on the DFD!

The data contained in the DFD is the same data described in the Data Dictionary. Therefore, we also compare, check, and correct it if necessary.

One more thing: all data that goes into a system must be used by that system for something. If it is not used, it is not needed. And all data that the system sends out and uses internally must come from somewhere (enter the system or be created within the system) — this is also something that needs to be checked. 

The detailed construction of a DFD is described in the book by K. Wiegers, edition 3, chapter 12, section "Data Flow Diagram".

### 3. Swimlane Diagram <div id="33"></div>

A swimlane diagram (cross-functional diagram) is used to examine and illustrate the business processes performed by users and the system, the interaction of users with each other, and/or the sequence of business processes or actions in a business process. This is what happens within the process in a data flow diagram. The diagram is divided into lanes, and in each lane there is a role involved in the system, the system itself, or an external system. Sometimes only the roles of users or departments are considered when only their interaction is required. The construction of the diagram is described in detail in chapter 12 of K. Wiegers "Requirements Development", section "Swimlane Diagram".

The diagram allows to check the completeness of the role model — roles and actions performed by them, interaction with external systems, order of execution of actions. Sometimes data used/generated in each process/action is added to the diagram. And then there is an opportunity to check with the data flow diagram, to identify inconsistencies, and if necessary — to conduct additional research and eliminate inaccuracies. 

The figure shows the software development life cycle in a swimlane diagram. It shows the main functions of each role and, in more detail, the functions of an analyst, as a supplement to the BSA 00 video on the functions of an analyst in software development.

For example, a diagram of the software development life cycle (Fig. 1) is constructed to describe the role and functions of an analyst in software development:

1. The purpose of the diagram is to familiarize students with systems analysis in IT. Beginners with the software development life cycle, the role of the analyst in software development and his/her functions.
2. Area of consideration: As-Is.
3. Diagram type: swimlane diagram.

*Figure 1*
![](misc/images/img1_eng.png)

### 4. Swimlane Diagram Extension <div id="34"></div>

Often the swimlane diagram is extended by adding artifacts (documents, queries, objects) created by representatives of a role during the execution of business process actions. Figure 2 shows the artifacts created by each role during the IT system design and implementation process, indicating the actions or processes during which the artifact is created. Artifacts and their relationships to actions/processes are highlighted in blue to make the diagram easier to read, but this is optional. The diagram also shows processes (rectangles with two lines on the vertical sides) and actions (rectangles) by different elements. A process may contain several actions that are not shown in the current diagram, but can be described in more detail in the next level diagram.  

In this case, we cannot say that the first diagram is wrong, even though it does not show the processes. Such a representation of the process (a simple rectangle, without double vertical sides) is quite common. It is important that the entire team understands it.

*Figure 2*
![](misc/images/img2_eng.png)

### 5. State diagram <div id="35"></div>

A state diagram shows the behavior of a particular object (class) in the system, the change of states of this object under the influence of events occurring in the system or external factors. State diagrams are usually constructed for one or more of the main objects in the system. Using the diagram for each state, it is possible to trace:

- possible states of the object in the system;
- previous state (state before the event);
- an event (action) that changes the state of the object;
- a role that initiates the transition;
- conditions of transition to a new state (transition to several states is possible, depending on the conditions);
- the state after the event.

The following figure shows the state diagram of the Request object from Task 1.  

![](misc/images/img3_eng.png)

The same information can also be presented in the table (shown partially).

![](misc/images/img4_eng.png)

## Chapter IV <div id="chapter-iv"></div>

### Description of tasks

### Task 1. Haircut Appointment <div id="41"></div>

The management of a chain of barbershops decided to implement an online booking system. The main objective is to develop the business by expanding the customer base through the possibility of online registration, as well as to reduce employee labour costs and manual labour by automatically informing customers through communication channels. 

Both registered and unregistered visitors can book an appointment on the website. When making an appointment, they can select the type of service: hairdressing or cosmetology, as well as the service itself, the master and the time from the available intervals. The system should provide automatic sending of reminders to clients through the communication channel chosen by the client (Telegram, WhatsApp, VK, SMS) according to the schedule set by the manager. After receiving a service, the system offers the client to evaluate the service and write suggestions on how to improve the work.

The schedule of masters and the services provided by each master should be entered by the manager, who may be more than one person. This person is also responsible for keeping the schedule up to date and adjusting it if necessary, communicating with customers manually, marking the service, charging and accepting payment, sending the payment data to the accounting department. The manager can also receive reports on completed services and view customer feedback.

Each master has the ability to view the schedule and appointments for their services, as well as customer reviews.

### Task 2. Delivery of Orders <div id="42"></div>

During the lockdown, many grocery stores and food companies dramatically increased their online sales and the need for quick delivery of small quantities to individual customers increased. 

A group of students got together and decided to create a delivery service startup. The idea is to quickly receive information about orders, pickup location and time, delivery location, desired delivery dates, and distribute this information to couriers who will pick up the order at the pickup location and deliver it to the delivery location. They decided to develop an online system where orders could be collected and quickly sorted for delivery by couriers.

The first step was to collect orders from stores and caterers in any way possible and have the operator enter them into the system in a consistent format, as well as developing a mobile application for the courier. The courier should be able to view order information, select an order from those available, book it, pick it up at the collection point and deliver it to the customer. The result of the courier's actions should be immediately reflected in the system via a mobile application. The system should also include a dispatcher who controls the couriers and reassigns orders if necessary. Information on received orders should be sent to the accounting department (to another IT system) to calculate delivery charges with order suppliers. Order delivery information should also be sent to the accounting department to calculate payment to couriers. Accrued payment should be transferred to the system and displayed in the courier's personal account. And there should also be an administrator's workstation, where couriers are registered and access rights are assigned to all of them.

## Chapter V <div id="chapter-v"></div>

### Exercise 00 — Building DFD, Level 0 <div id="51"></div>

**For each task:**
Build a Level 0 Data flow diagram:

1. Specify the purpose of the diagram.
2. Specify the area of consideration: As-Is or To-Be.
3. Show the external entities that interact with the system in the rectangles on the diagram.
4. Show the processes (stakeholder actions on the data) in ovals.
5. Show the content of the information flows on the arrows.
6. Show the data stores and the content of the information stored in the system in parallel line segments.
7. Follow the rules:
   1. All processes (ovals) must be numbered. On a level 0 diagram — in whole numbers.
   2. The processes are named: verb+object.
   3. Comprehensible domain names (not technical names of system database entities) are used to identify the object.
   4. Processes do not interact with each other directly, but through data stores.
   5. Data flows between stores and external entities or between each other through a process (not directly).
   6. The diagram does not show the sequence of processes and actions.
   7. The diagram must be readable.
8. Indicate your answers in the turn-in file ex00\_<product prefix>\_dfd.xxx (xxx is an extension).

### Exercise 01 — Building a Swimlane Diagram <div id="52"></div>

**For each task:**

Build a swimlane diagram:

1. Specify the purpose of the diagram.
2. Specify the area of consideration: As-Is or To-Be.
3. Select roles for the diagram: stakeholders, divisions, external systems. 
4. Show the lanes for the roles in the diagram.
5. Show the process steps as rectangles.
6. Show the process steps performed by the role on the corresponding track.
7. Show transitions between process steps with arrows.
8. Show the solutions in rhombuses.
9. Show the solutions on the arrows coming out of the rhombus.
10. Show the beginning and end of the process with a start/finish circle.
11. Indicate your answers in the turn-in file ex01\_<product prefix>\_swd.xxx (xxx is an extension).

### Exercise 02 — Extending the Swimlane Diagram <div id="53"></div>

**For each task** add the created artifacts to the swimlane diagram:

1. Copy the swimlane diagram, change the name.
2. Specify the purpose of the diagram.
3. Specify the area of consideration: As-Is or To-Be.
4. Add to each role in the swimlane diagram the artifacts it creates: documents, developed code, logged bugs, queries, etc.
   1. Show artifacts for each role on the lane that are developed or adjusted by the role representatives, show it on the role lane;
   2. Specify with a dotted line for each artifact the relationship to the source where the artifact is created/corrected;
   3. It is acceptable to group artifacts, i.e., to specify multiple artifacts in the same pool if they are created by the same role in the same process (or when performing the same action).
5. Indicate your answers in the turn-in file ex02\_<product prefix>\_adswd.(xxx is an extension).

### Exercise 03 — State Diagram <div id="54"></div>

**For each task:**

1. Select an object (domain entity) that has a life cycle. In task 1 — excluding the object Service request.
2. Specify the purpose of the diagram.
3. Specify the area of consideration: As-Is or To-Be.
4. Build a state diagram of the selected object:
   1. Select the names of the object states;
   2. Indicate each state of the object in the diagram;
   3. Connect the previous and next object states with arrows;
   4. Indicate the event (action) next to the arrow that transforms the object from one state to another;
   5. Specify the initiator of each event (action);
   6. Specify conditions if there are branches;
   7. Specify the beginning and end of the object life cycle.
5. Indicate your answers in the turn-in file ex03\_<product prefix>\_dst.xxx (xxx is an extension).

### Exercise 04 — State table <div id="55"></div>

**For each task** build a table of object states:

1. Select objects (domain entities) that have a life cycle.

For an object for which no complete state diagram of the object has been built:

1. Specify the object.
2. Specify the purpose of the diagram.
3. Specify the area of consideration: As-Is or To-Be.
4. Build a state table:
   1. Select names of object states.
   2. Specify in the table row:
      1. previous and subsequent states of the object;
      2. an event (action) that transforms an object from a previous state to a subsequent state;
      3. the initiator of each event (action);
      4. conditions, if there are branches.
   3. Specify the beginning and end of the object life cycle.
5. Indicate your answers in the turn-in file ex04\_<product prefix>\_tst.xxx (xxx is an extension).
