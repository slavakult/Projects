# Requirements

Summary:

Today you will learn about software requirements, their types, levels, relationships and dependencies, as well as the "As-Is" and "To-Be" models. You will build a context diagram, identify stakeholder roles, problems, needs and product business requirements. 

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Preamble](#11)
2. [Chapter II](#chapter-ii) \
   2.1. [General Rules](#21)
3. [Chapter III](#chapter-iii) \
   3.1. [Types and Levels of Requirements](#31) \
   3.2. [As-Is and To-Be Models](#32) \
   3.3. [Context Diagram](#33)
4. [Chapter IV](#chapter-iv) \
   4.1. [Task 1. Haircut Appointment](#41) \
   4.2. [Task 2. Delivery of Orders ](#42)
5. [Chapter V](#chapter-v) \
   5.1. [Exercise 00 — Roles and Their As-Is Actions ](#51) \
   5.2. [Exercise 01 — Creating a Context Diagram ](#52) \
   5.3. [Exercise 02 — Solving Stakeholder Problems](#53) \
   5.4. [Exercise 03 — Checking Input and Output Data Flows](#54) \
   5.5. [Exercise 04 — Adding Artifacts](#55)

## Chapter I <div id="chapter-i"></div>

![](misc/images/Illustration_02.jpg)

### Preamble <div id="11"></div>

A requirement is a useful representation of a need or solution. In this project, you will learn how to classify requirements that describe a system from different perspectives, and how and why requirements are related. You will also learn how to create a context diagram.

**Literature:**

1. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition, chapter 1 and others.
2. BABOK v3 «A Guide to the Business Analysis Body of Knowledge» IIBA.
3. Dean Leffingwell, Don Widrig "Managing Software Requirements", part 1, chapter 4.
4. Elizabeth Hull, Ken Jackson, Jeremy Dick "Requirements Engineering".
5. Ilya Kornipaev "Requirements for Software: Recommendations on Gathering and Documentation".

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

### 1. Types and Levels of Requirements <div id="31"></div>

Requirements are a description of the needs of what is to be implemented. They describe the behavior of the system, its properties, characteristics and constraints. Requirements describe the system in all its aspects, from all sides. 

The most used requirements typing is given in the book "Software Requirements" by Karl Wiegers and Joy Beatty. You can see them in the table below.

**Types of requirements**

| Term                      | Definition                                                   |
| ------------------------- | ------------------------------------------------------------ |
| Business requirement      | High-level business objective of the organization or system customers |
| Business rule             | Defining or constraining, policy or rule                     |
| User requirement          | Tasks that users should receive from the system or perform using the system |
| External interfaces       | Interaction with other systems or the user                   |
| Constraint                | Restrictions of the available implementation choices         |
| System requirement        | A top-level requirement for a product that contains multiple subsystems, which could be all software or software and hardware. |
| Functional requirement    | A behavior that a system will exhibit under specific conditions. |
| Nonfunctional requirement | Properties or features that the system must exhibit, or constraints that the system must respect |
| Quality attribute         | Characteristics of properties, features, constraints of the system |

Requirements of different types for a software product are always interrelated, interdependent, and mutually influential. The relationships between requirements and their levels are illustrated in Figure 1 from the book "Software Requirements" by Karl Wiegers and Joy Beatty, third edition, Chapter 1. However, you should be aware that requirements from different groups of users (different roles) are collected at one level, under a single concept, e.g. user requirements, and that there may be conflicting requirements in terms of preferences.

*Figure 1. Relationships and levels of requirements*

![](misc/images/img1_eng.png)

### 2. "As-Is" and "To-Be" Models <div id="32"></div>

**As-Is** is a model of the current state of a system or organization. It shows the current processes, objects, roles, and actions. The purpose of building an As-Is model is to identify the current state and problem areas. Based on the As-Is model, we need to understand what should be done to solve the problem and build a **To-Be** model — the expected state of the future system and/or changes in processes and/or the system itself. And further, to determine the sequence of moving from the current to the future state of the system.

### 3. Context Diagram <div id="33"></div>

A context diagram characterizes a current (existing) or future (expected) system in its relationships with the surrounding world — stakeholders and related systems. It shows what information flows or control actions are transmitted from the outside to the inside of the system, and what is transmitted from the system to the outside, and who is doing it. A context diagram does not show what is done inside the system, only the "black box". It also helps define the boundaries of the system.

#### Description

The diagram shows the environment (domain, context) in which the system exists, what and who surrounds it and interacts with it. First of all, these are the users of the system (in different roles) and the external systems that exchange information with it. 

Understanding the context surrounding the system helps to identify:

1. Actions that different user roles expect the system to perform; 
2. Data flows that the system exchanges with other systems;
3. Control actions from outside the system and to the outside. 

Each external entity can be either a source or a receiver of data for the system, or both. A context diagram allows you to identify all the points outside the system with which the system interacts in some way, and to specify how. The context diagram thus allows you to define the boundaries of the system: to list the parties interacting with the system, the actions expected of the system, and the data both received by the system and generated and transmitted outside the system.

To keep things simple, the context diagram does not include:

- the means of data transmission (protocols) by which data is transmitted to and from the system;
- interaction interfaces that users and third-party systems use to communicate with the system.

#### Elements

The diagram consists of the following parts:

1. The system itself, usually is an oval; 
2. External entities that interact with the system (usually a rectangle):
   - users (in a specific role);
   - organizations;
   - third-party systems, devices capable of receiving, or generating and transmitting data. \
     Each entity must have at least one data flow coming in or out of it to the system. \
     A noun written in a rectangle indicates the user role, organization (department), or third-party system. 

3. System interaction with external entities (usually lines with arrows and captions):
   - data flows;
   - tangible or intangible objects (information about them);
   - control actions. \
     The arrow between the system and the external entity indicates the direction of information transmission with a description of the data or actions To-Be transmitted.  

An example of a context diagram for task 1 is shown in Fig. 2.

*Figure 2.*
![](misc/images/img2_eng.png)

## Chapter IV <div id="chapter-iv"></div>

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

### Exercise 00 — Roles and Their As-Is Actions   <div id="51"></div>

**For each task:** 

1. Create a table of roles and their actions in the current state (As-Is) (refine for task 1).
2. Write out all the intended roles of stakeholders and their actions from the task description.
3. Specify the problems that the stakeholder roles face in the current state (As-Is).
4. Specify in the table not only the roles of stakeholders directly interacting with the system, but also the roles of other stakeholders. Update the stakeholder directory of the previous project. Load the updated directory into src.
5. Indicate your answers in the turn-in file ex00\_<product prefix>\_asis.docx.

**Recommendations for the task:**

Check the indication of all problems covered in the project Stakeholders, Exercise 02 — Interests, Needs, Problems of Stakeholders.

A part of a table identifying the roles, their actions and problems using Task 1 as an example. 

| Identifier | Stakeholder | Action                             | as   is        |           | Problems                                                     |
| ---------- | ----------- | ---------------------------------- | -------------- | --------- | ------------------------------------------------------------ |
|            |             |                                    | over the phone | in person |                                                              |
| st00200    | Client      | Making/rescheduling an appointment | +              | +         | It is difficult for the client to make an appointment (to call) |
| st00200    | Client      | Getting a discount                 | -              | +         |                                                              |
| st00200    | Client      | Getting a reminder                 | +   /-         | -         | It's hard for a manager to text everyone manually            |
| st00300    | Visitor     | Registration                       | -              | +         |                                                              |
| st00300    | Visitor     | Making/rescheduling an appointment | +              | +         | It is difficult for the client to make an appointment (call) |
| st00300    | Visitor     | Getting a discount                 | -              | -         |                                                              |
| st00300    | Visitor     | Getting a reminder                 | -              | -         | Manager loses phone numbers without registration             |

### Exercise 01 — Creating a Context Diagram <div id="52"></div>

**For task 2:**

1. Develop a context diagram.
2. Indicate in the diagram the stakeholders, stakeholder actions and control actions directed to or received from the system.
3. Indicate in the diagram the third-party systems and the data flows that the system uses to interact with them.
4. Place the diagram in the turn-in file ex01\_<product prefix>context.xxx (xxx — is an extension).

**Recommendations for tasks:**

An example of the context diagram of Task 1 is shown in the figure.

![](misc/images/img3_eng.png)

### Exercise 02 — Solving the Problems of Stakeholders <div id="53"></div>

**For each task:**

1. Add user actions of the system To-Be in the table created in the **Exercise 00 — Roles and Their Actions As-Is**, based on the context diagram.
2. Refine the diagram or source table if necessary.
3. Write a To-Be condition for each problem — whether the solution helps to resolve the problem when applying the system.
4. Indicate your answers in turn-in file ex02\_<product prefix>\_tobe.xlsx.

**Recommendations for tasks:**

Example of part of the finalized table for task 1.   

| Identifier | Stakeholder (Role in the project) | Action                             | as   is        |           | Problems                                                     | to   be       |           | Problem Solution                                             |
| ---------- | --------------------------------- | ---------------------------------- | -------------- | --------- | ------------------------------------------------------------ | ------------- | --------- | ------------------------------------------------------------ |
|            |                                   |                                    | over the phone | in person |                                                              | In the system | In person |                                                              |
| st00200    | Client                            | Making/rescheduling an appointment | +              | +         | It is difficult for a client to make an appointment (to call) | +             |           | Making it easier for the client to make an appointment       |
| st00200    | Client                            | Getting a discount                 | -              | +         |                                                              | -             | +         | -                                                            |
| st00200    | Client                            | Getting a reminder                 | +   /-         | -         | It is hard for a manager to text everyone manually           | +             |           | Reminders will be sent automatically                         |
| st00300    | Visitor                           | Registration                       | -              | +         |                                                              | +             |           | Simplification of registration    Reducing the manager's workload |
| st00300    | Visitor                           | Making/rescheduling an appointment | +              | +         | It is difficult for a client to make an appointment (to call) | +             |           | Making it easier to make an appointment                      |
| st00300    | Visitor                           | Getting a discount                 | -              | -         |                                                              | -             | -         | -                                                            |
| st00300    | Visitor                           | Getting a reminder                 | -              | -         | Manager loses phone numbers without registration             | -             |           | Ability to send reminders automatically                      |

### Exercise 03 — Checking Input and Output Data Flows <div id="54"></div>

**For each task:**

1. Create a table of input-output data flows based on the context diagram.
2. In case of differences in the table refine the context diagram and correspondence table.
3. If there are deviations, make a note to the table and explain.
4. Indicate your answers in turn-in file ex03\_<product prefix>\_flows.xlsx.

### Exercise 04 — Adding Artifacts <div id="55"></div>

**For each task:**

1. Write down new concepts and terms found in the task into a glossary.
2. Find descriptions of concepts and terms and put them in a glossary.
3. Add new identified stakeholders to the stakeholder directory.
4. Specify attributes of new stakeholders.
