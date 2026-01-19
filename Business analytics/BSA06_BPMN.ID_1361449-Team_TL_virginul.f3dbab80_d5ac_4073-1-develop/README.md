# Modeling business processes

Summary:

In this project, you will continue to learn about the basic models and representations that an analyst develops during the analysis and design process. You will learn about BPMN diagrams, their scope, and how to build them. You will also compare it to the one you developed earlier, identify inconsistencies, and complete them.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Preamble](#11)
2. [Chapter II](#chapter-ii) \
   2.1. [General Rules](#21)
3. [Chapter III](#chapter-iii) \
   3.1. [Business processes](#31) \
   3.2. [Recommendations for Work with Business Processes](#32) \
   3.3. [BPMN Diagram](#33)
4. [Chapter IV](#chapter-iv) \
   4.1. [Task 1. Haircut Appointment](#41) \
   4.2. [Task 2. Delivery of Orders)](#42)
5. [Chapter V](#chapter-v) \
   5.1. [Exercise 00 — Preparatory Work](#51) \
   5.2. [Exercise 01 — Identification of Main Business Processes](#52) \
   5.3. [Exercise 02 — Discussion of Business Processes](#53) \
   5.4. [Exercise 03 — Description of the Main Business Processes](#54) \
   5.5. [Exercise 04 — Development of Business Process Diagrams](#55) \
   5.6. [Exercise 05 — Revision of the Main Business Process Diagrams](#56)

## Chapter I <div id="chapter-i"></div>

![](misc/images/Illustration_06.jpg)

### Preamble <div id="11"></div>

In this project you will: be introduced to the concept of "business process" and techniques for building business process diagrams; learn about the BPMN notation; build diagrams in this notation; compare business process models with other previously created artifacts, which will allow you to identify inconsistencies and better understand needs and problems. 

The current project is a group project.

### Literature:

1. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition, amplified.
2. Vladimir Repin "Business Process Modeling in BPMN Notation. Manual for beginners. Part I".
3. [BPMN Description](https://www.businessstudio.ru/wiki/docs/current/doku.php/ru/csdesign/bpmodeling/bpmn_notation) by Business Studio.
4. [Blog about business processes and BPMN](https://bpmn.pro/bpmn/chto-takoe-bpmn). 
5. Microsoft "[A beginner's guide to using BPMN in everyday work](https://www.microsoft.com/ru-ru/microsoft-365/business-insights-ideas/resources/the-guide-to-using-bpmn-in-your-business)".
6. Comindware's Blog "[BPMN 2.0 notation: key elements and description](https://www.comindware.ru/blog/%d0%bd%d0%be%d1%82%d0%b0%d1%86%d0%b8%d1%8f-bpmn-2-0-%d1%8d%d0%bb%d0%b5%d0%bc%d0%b5%d0%bd%d1%82%d1%8b-%d0%b8-%d0%be%d0%bf%d0%b8%d1%81%d0%b0%d0%bd%d0%b8%d0%b5/)".

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

### Theory

In this project, we will use a process approach to solve our problems. The process approach involves viewing the activities of an organization as a system of interrelated and coordinated processes that the organization performs to achieve its primary goals.

### 1. Business Processes <div id="31"></div>

**Business process** is a sequence of actions (events, operations, work), limited by a beginning and an end, aimed at achieving a given result (e.g. creation of a product or service).

A business process is characterized by these basic elements:

- ***Business process purpose/result (output)*** — what the business process is for. A business process always aims to achieve a result. Typically, a business process is named according to its purpose. ***For example***, billing for telephone calls.
- ***Business process owner*** — the person or official responsible for performing the process and achieving the result. Non-group role. ***For example***, the head of the accounts team of a mobile phone company.
- ***Executors*** — people (groups of people) who perform certain actions of a business process. People who perform identical actions are grouped into roles ***For example***, an employee of the accounts team of a cell phone company. 
- ***Business process input*** — the resources required to create the result of the business process. Input resources (materials, information data) are consumed or transformed into an output. ***For example,*** the timing of telephone calls to calculate payment for those calls.

In addition, the business process has:

- ***Beginning*** — an event that initiates a business process. ***For example,*** the end of the period when calculating telephone charges.
- ***Ending*** — result event. The result of a business process can be either successful or unsuccessful. *For example,* the accrued payment for telephone calls for the period.
- ***Applicable resources*** — applied and unchanged in the business process. ***For example,*** telephone tariff reference data.
- ***Business process steps*** — business process actions executed in a specific sequence. ***For example,*** the actions performed for telephone charges.
- ***Business process description*** — textual or/and graphical description of the sequence of actions; indication of the roles executing the actions and conditions of execution. 

A business process can consist of several sub-processes, procedures, and functions that are designed to achieve the goal of the main business process. The output of one business process may be the input for another.

### 2. Recommendations for Work with Business Processes <div id="32"></div>

Identifying business processes is a creative process. There is no one right way to do it. It is always the result of team agreements.

It is important that the **result of the business process implementation** consists of:

1) fulfillment of business requirements;
2) solving key stakeholder problems identified in the task;
3) execution by the system roles their functions. 

The business requirements, key stakeholder concerns of the task and functional role model were reviewed in the BSA03 project. 

**Business Process Categories**

- *main:* processes that add value to the business;
- *supporting:* supporting processes, required for the correct execution of the main processes, do not add value to the business but ensure that the main business processes are executed.   

**Criteria for separation** into business processes:

1. difference in objectives, i.e. different business process needs;
2. a business process must get a result (output).

**The main business processes** must provide the ability to:

1. fulfill business requirements;
2. solve key stakeholder problems identified in the task;
3. fulfill the functions of the system roles.

**Execution order**

1. define the area of consideration: as-is (problem area) or to-be (solution area);
2. decompose, identify categories: main and supporting;
3. consider main and supporting business processes separately;
4. identify and consider the main business processes first, then the supporting ones; 
5. consider the most important and business-critical main processes first, then the rest;
6. when considering supporting business processes, first consider those without which the main business processes cannot achieve the required result.

**Decomposition:** to identify business processes, don't forget the rules (from the BSA00 project):

- subordination,
- singularity of criterion,
- integrity.

Also:

1. Apply decomposition rules separately to the main processes and separately to the supporting processes;
2. Reasonable violations of decomposition rules are possible; for example, integrity violations are acceptable for supporting processes: it is not always possible to specify all supporting business processes at once. 

Business processes are **not recommended** to be identified **by role function**. The process approach is designed to see the end-to-end chain of activities between the roles of the system. It is designed to identify the interaction between different groups of participants in the process of achieving a goal and producing a result.

It also helps to identify:

1. The purpose of the business process description;
2. From whose perspective we are describing;
3. Boundaries, depth of description.

### 3. BPMN Diagram <div id="33"></div>

Various graphical notations are often used to visualize business processes. 
In the current project, we will consider one of them — [BPMN](https://ru.wikipedia.org/wiki/BPMN) (Business Process Model and Notation).

BPMN is:

- An intuitive (and therefore common) way to model business processes;
- A language for modeling business processes.

There are the following types of diagrams in BPMN:

1. The process diagram describes the sequence of tasks and events, the execution conditions, and the logic of the business process.
2. Diagrams describing the data exchange:
   1. The Collaboration diagram describes the message flows;
   2. Simplified interaction models:
      1. The Choreography diagram describes a sequence of interactions between participants;
      2. Conversation diagram describes the top level of interaction between the parties: organizations, divisions and so on.

BPMN elements are represented as special symbols. Usually a basic set is enough to understand the principles of notation and modeling and to develop most of the diagrams.
The language of business process description is based on the following objects:

- Event;
- Activity;
- Gateway;
- Flow;
- Data;
- Artifact;
- Swimlane, Pool.

Good descriptions of BPMN:

- [Description of the BPMN](https://www.businessstudio.ru/wiki/docs/current/doku.php/ru/csdesign/bpmodeling/bpmn_notation) by Business Studio.
- [https://www.comindware.ru/blog](https://www.comindware.ru/blog/%d0%bd%d0%be%d1%82%d0%b0%d1%86%d0%b8%d1%8f-bpmn-2-0-%d1%8d%d0%bb%d0%b5%d0%bc%d0%b5%d0%bd%d1%82%d1%8b-%d0%b8-%d0%be%d0%bf%d0%b8%d1%81%d0%b0%d0%bd%d0%b8%d0%b5/)/notation-bpmn-2-0-elemets-and-description.

There are two types of processes in BPMN from a modeling perspective:

- Executable, which can actually be executed using special Business Studio or Bizagi software;
- Non-executable, which are used for study, coordination, and demonstration.

Many teams use non-executable diagrams and aim to create them with a minimal, basic set of elements. This approach allows people to quickly learn and understand the notation, not only analysts, but also developers, system customers, users, which contributes to faster work of the team (faster development, faster coordination). Executable processes require strict adherence to all rules of BPMN notation and deeper detailing.

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

### Exercise 00 — Preparatory "Work" <div id="51"></div>

**For each task:**
Pick up the following artifacts from previous projects (chapter 1):

1. glossary;
2. onion diagram;
3. context diagram;
4. the problems to be solved by the system;
5. business requirements (business goals);
6. stakeholder roles;
7. role functions in the system;
8. data flows sent/received by external systems.

Indicate your answers in a file with corresponding names ex00\_<product prefix>\_<file name>.

### Exercise 01 — Identification of Main Business Processes <div id="52"></div>

**For task 1** identify main business processes. 

1. Identify business processes of level 1. Follow the decomposition rules. In case of violation, provide an explanation.
2. For each business process, select one person from your group and assign him/her to the role of business process owner. Determine who he/she is according to the role model of the task.
3. Make a list of the main business processes, specify:
   1. name (purpose) of the business process;
   2. business process identifier (alphanumeric, up to 5 characters); 
   3. business process result;
   4. owner (role in the task, last name, first name of the person assigned from the group).
4. Consider the criteria for identifying business processes:
   1. each business process must have a result;
   2. the results of business processes of the same level should be different.
5. Indicate your answers in the file ex01\_<product prefix>\_mpr.xlsx.

### Exercise 02 — Discussion of Business Processes <div id="53"></div>

**For task 1** have a discussion on each of the main business processes. 

1. Prepare questions for a business process discussion.
2. Consider both Exercise 03 of the current project and your own understanding of the business process when preparing questions.
3. Discuss the business process (it can be a role-playing game, brainstorming session, workshop — the team's choice).
4. Prepare a report of the discussion (discussed in detail in the BSA03 project), indicate:
   1. business process name;
   2. business process identifier;
   3. topic, purpose of the discussion;
   4. date of discussion, form of discussion, list of participants;
   5. facilitator, clerk, business process owner;
   6. issues discussed;
   7. answers to questions;
   8. on issues that caused controversial opinions: write down the opinions of the participants, the opinion of the business process owner, and the decision made.
5. Place the report in the file ex02\_<product prefix>\_<business process identifier>\_disc.docx. 

### Exercise 03 — Description of the Main Business Processes <div id="54"></div>

**For task 1** describe each of the main business processes, write them in a single table. 

1. Specify for each main business process:
   1. business process name;
   2. business process identifier;
   3. Start (input): 
      1. initiating event;
      2. resources to create a product (result);
   4. end (exit): 
      1. resulting event; 
      2. the finished product/result of a business process;
   5. owner:
      1. role;
      2. surname, first name of the assigned member of the group; 
   6. list of business process executors (roles in the task);
   7. used resources (information data used in the business process);
   8. relationships with other main business processes.
2. Indicate your answers in the file ex03\_<product prefix>\_mpr.xlsx.

### Exercise 04 — Development of Business Process Diagrams <div id="55"></div>

**For task 1** create a process diagram of each main business process in BPMN notation.

1. Specify the name of the business process and its identifier in the diagram.
2. Specify the owner of the business process (who is responsible for execution) next to the name.
3. Specify the initial event, what the event is about, who the event comes from (executor or automatically).
4. Specify the input of the business process: the resources required to create the result of the business process (information, personnel) from which the result is obtained.
5. Specify process steps, branches, data and relationships.
6. Specify intermediate events if necessary.
7. Apply lanes/pools or specify executors on footnotes (artifacts) if necessary. 
8. Specify the end event and result of the business process.
9. Indicate your answers in the file ex04\_<product prefix>\_bpmn\_N.xxx (xxx is an extension, N — business process identifier).

### Exercise 05 — Revision of the Main Business Process Diagrams <div id="56"></div>

**For task 1** check the consistency of the main business process diagrams and other task artifacts.

1. Check the consistency of the stakeholders and the roles in:
   1. context diagram;
   2. onion diagram;
   3. stakeholders list;
   4. main business process diagrams.
2. Check that the glossary contains the domain concepts specified in the main business process diagrams.
3. Check that the problems for which the system is being created can be solved in the execution of the main business processes.
4. Check that the business requirements of the system can be achieved by the main business processes.
5. Check that the main business processes ensure that the functions of the system roles are fulfilled. 
6. Place the results in the "Artifact Comparison" table (https://docs.google.com/spreadsheets/d/1tKYX2C6t6lXdRNa14qHG4j2gKa\_mQSW5/edit#gid=2122219759).
7. In case of inconsistency:
   1. report the inconsistency for each case in a table;
   2. indicate the need (or lack of need) to modify the artifacts under consideration;
   3. correct an artifact that requires clarification.
8. Indicate your answers in the file ex05\_<product prefix>\_rev.xlsx.
9. Place a new revision of the refined artifact with a ex05 prefix in the name.
