# Domain and information model

Summary:
You will be introduced to the concept of "domain" and learn how to identify domain entities. You will learn what a System Information Model is, how to build one, and how to test the model using CRUD.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Preamble](#11)
2. [Chapter II](#chapter-ii) \
   2.1. [General Rules](#21)
3. [Chapter III](#chapter-iii) \
   3.1. [Domain](#31) \
   3.2. [Identification of Entities and Actions With Them](#32) \
   3.3. [CRUD Entity Testing](#33) \
   3.4. [Data Dictionary](#34) \
   3.5. [ER Diagram](#35)
4. [Chapter IV](#chapter-iv) \
   4.1. [Task 1. Haircut Appointment](#41) \
   4.2. [Task 2. Delivery of Orders](#42)
5. [Chapter V](#chapter-v) \
   5.1. [Exercise 00 — Entity Identification](#51) \
   5.2. [Exercise 01 — Entity Testing by CRUD](#52) \
   5.3. [Exercise 02 — Building a Data Dictionary](#53) \
   5.4. [Exercise 03 — Building a Logical Data Model](#54)

## Chapter I <div id="chapter-i"></div>

![Illustration_04](misc/images/Illustration_04.jpg)

### Preamble <div id="11"></div>

In the previous project, for each system under development, you identified the business requirements (high-level customer goal), got to know the stakeholders — those who are interested in the system in one way or another, learned what a context diagram is, how to build it, and how to use it. In this project, you will learn what a domain is, you will learn to recognize the domain entities with which the system works. You will learn what a CRUD model is and you will test your domain entities using the CRUD model.

**Literature:**

1. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition, amplified.
2. BABOK v3 "A Guide to the Business Analysis Body of Knowledge" IIBA.
3. Dean Leffingwell, Don Widrig "Managing Software Requirements".

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

### 1. Domain <div id="31"></div>

**Domain** is a part of the real world that is considered within certain boundaries. 

These are circumstances and conditions that:

- influence the design/change of the system;
- are influenced by the design/change of the system;
- contribute to the understanding of the system.

The domain may include

- real world objects,
- data flows,
- people
- organizations,
- business processes,
- ideas,
- technologies,
- goals and tasks,
- relationships between any of the above.

That is, the domain includes not only the system and the external entities related to it, but also all the concepts contained in the system and somehow related to it. Everything that enters and surrounds the system. 

Figure 1 shows the context of the system according to Task 1, the green area is the context, the dashed line is the boundaries of the context. In the context, we have selected the system and its environment (external entities) that directly interact with the system — the regulator and the sanitary and epidemiological surveillance. 

Note that the concept of context is not directly related to the Context class in programming (which provides access to the underlying functions of an application).

*Figure 1.*

![img1_eng](misc/images/img1_eng.png)

Relationships and dependencies are important concepts in the domain. It is the knowledge of concepts, the understanding of dependencies that exist in the domain, that is valuable for an analyst involved in the development of IT systems. But it takes a lot of time to understand a new domain well. Therefore, knowledge of one or more domains is highly valued in IT teams. Read more about methods for immersing yourself in a new domain:

1. [Irina Gertovskaya "Immersion in a new domain. Analyst's check-list"](https://rutube.ru/video/3e68d3f9e376e6a212acef561d4166ff/?ysclid=m0m7njiwmy714477779).
2. [Marina Davydova "Workshop: Research of the domain as a quest in the analyst's work"](https://rutube.ru/video/695293ff417d1f16dd22d98e86cd554e/).

### 2. Identification of Entities and Actions With Them <div id="32"></div>

There is a simple way to identify entities in a domain: in texts describing problems and needs, we distinguish "noun-verb" or "noun — verbal noun" pairs. If a noun is an object in the real world (or in the virtual world, but not yet in our system), and if it occurs several times, it is a candidate for objects (entities) in the system. Read more about the order of entity identification:

1. Identifying candidates for entity.

   Underline nouns and especially noun-verb or verb-noun pairs in texts describing a task or problem. When actions are performed on something, it is a candidate for system objects.

2. Identifying entities.

   Identify from the underlined nouns, objects, events — everything that will be present in the data on which users or the system itself will work in our system. Each entity must be coherent and logically separate from all others.

3. Defining the key properties of each entity.

   Define properties (attributes) that are unique to each entity. Sometimes in the text it is a noun that is somehow related to the noun identified as the entity. There may be one or more unique attributes for each entity. 

4. Defining relationships between entities.

   Identify relationships between entities:
   - 1:1 (one-to-one);
   - 1:М (one-to-many);
   - М:1 (many-to-one);
   - М:М (many-to-many).

5. Mapping attributes to entities.

   Mapping attributes to entities, taking into account how the business will use the data. Identification of possible attribute values and conditions, constraints.

6. Assignment of keys and degrees of normalization.

   Normalization is a method of organizing data models in which identifiers (keys) are assigned to groups of data to establish relationships between them without repeating the data.

7. Completion, testing of the data model.

   Modeling is an iterative process, it should be repeated and refined to meet the needs of the business.

### 3. CRUD Entity Testing <div id="33"></div>

A good way to check the completeness of actions on an entity is the CRUD technique. Each instance of an entity should be tested for:

- Creation;
- Reading;
- Updating;
- Deletion.

Perhaps some of these actions should not be performed on instances of individual entities, for example, deletion is not allowed. But this should be a conscious decision, because even if we want to have information about all past activities, we need to think about what to do when there are too many of them. Perhaps instead of deleting, we can perform the action Transfer to archive. 

Table 1 shows the CRUD matrix for the Service entity in Task 1.

Sometimes, when creating the matrix, there are questions that are not answered in the task text. We should clarify these questions with the customer (if there is one) or come up with an acceptable variant (hypothesis), reflect it in an addendum to the task condition (obligatory!) and continue analyzing and developing the system based on the hypothesis.

[Read more about CRUD testing](https://conf.uml2.ru/index.php?all_classes&class_id=trebovaniya-ne-menyayutsya-eto-vy-ikh-nedovyyavili--10-tekhnik-proverki-polnoty-trebovanii)

*Table 1*

| Entity   | CREATE          |                        | READ                    |        | UPDATE          |                             | DELETE                |                                        |
| -------- | --------------- | ---------------------- | ----------------------- | ------ | --------------- | --------------------------- | --------------------- | -------------------------------------- |
|          | Role            | Action                 | Role                    | Action | Role            | Action                      | Role                  | Action                                 |
| Service  | Client, visitor | Making an appointmnent | Master, Manager         | views  | Client, Manager | Changes the type of service | Manager               | Transfers to the archive after payment |
| Schedule | Manager         | Creates                | Master, Client, Visitor | Views  | Manager         | Changes                     | Check with the client | Check with the client                  |

### 4. Data Dictionary <div id="34"></div>

A **data dictionary** is a tool, a technique, that allows data to be described in business terms and to contain other information about the data: information about data types and formats, details of data structures and regulatory reference information, and possibly other constraints such as security. Thus, data dictionaries are a way to maintain metadata.

|                          | Glossary                                              | Data Dictionary                                              |
| ------------------------ | ----------------------------------------------------- | ------------------------------------------------------------ |
| What it contains         | Terms, abbreviations, concepts, business description  | Concepts, business description, technical description of data:<br> - data types,<br> - data formats,<br> - data structure details,<br> - constraints,<br> - binding to regulatory reference information,<br> - security policy,<br> - etc. |
| Content                  | Atomic concepts: one term - one object of the domain  | May contain composite elements that include several simple or also composite elements |
| Specifics, peculiarities | General-purpose, describes the domain for any project | Specific to IT system development, implementation, maintenance projects |

### 5. ER diagram <div id="35"></div>

One way to visualize the domain is through the data model of an Entity-Relationship Diagram (ER Diagram).
Remember that a model is a simplified description of reality that allows you to explore or manipulate an object. Depending on the team's goal, we develop such data models:

- Conceptual model;
- Logical model;
- Physical model.

**Conceptual Data Model**

Defines the basic constructs, describes the semantics of the domain.
It is often used in the initial planning phase and does not contain detailed attribute information.
Includes:

- Main entities;
- Relationships.

The development of a conceptual data model is the responsibility of the analyst.

**Logical Data Model**

Represents the content and relationships of the business and is an extension of the conceptual model. It represents business information and is defined by business rules and a specific data manipulation technology.
Includes:

- Entities;
- Attributes;
- Keys;
- Relationships.

The logical data model is often developed by an analyst, but in a team with an architect or developer.

**Physical Data Model**

Provides code development and all that goes with it. Tied to a specific DBMS.
Includes:

- All required tables, columns, relationships;
- Database properties for physical implementation of databases:
  - Database performance;
  - Indexing strategy;
  - physical repository;
  - denormalization.

A physical data model based on a logical model is developed by a developer or architect.

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

### Exercise 00 — Entity Identification <div id="51"></div>

**For each task:**

1. Identify at least 7 entities (following the order of entity selection) with which the system will work.
2. Define a name for each entity, specify the purpose.
3. Define the main (key) attributes for each entity.
4. Indicate your answers in the turn-in file ex00\_<product predix>\_entity.xlsx.

### Exercise 01 — Entity Testing by CRUD <div id="52"></div>

**For task 1:**

1. Perform a CRUD test of the completeness of actions for each entity.
2. Specify in a table (similar to the one shown in Fig. 2 in item 3) for CRUD testing:
   1. Specify in the table the stakeholder roles and actions under which the CRUD operation is performed;
   2. In case it is not clear from the task or interview conditions who performs the operation and when, suggest a hypothesis or indicate the need for clarification from stakeholders (highlight in color).
3. Indicate your answers in the turn-in file ex01\_<product prefix>\_crud.xlsx.

### Exercise 02 — Building a Data Dictionary <div id="53"></div>

**For each task:**

1. Build a data dictionary.
2. Include entity name, mnemonics, concept description, data type, and obligingness in the data dictionary.
3. Place the table in the turn-in file ex02\_<product prefix>\_dict.xxx (xxx is an extension).

### Exercise 03 — Building a Logical Data Model <div id="54"></div>

**For each task:**

1. Build an ER diagram — a logical data model.
2. Include your selected entities in the ER diagram, supporting directories and decoupling tables for M:M relationships.
3. Specify the multiplicity of relationships between entities in the ER diagram.
4. Describe with verbs the relationships between entities in the ER diagram.
5. Place the diagram in the turn-in файле ex03\_<product prefix>\_model.xxx (xxx is an extension).
