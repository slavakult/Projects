# Databases and data dictionary

Summary:
In this project, you will create a logical database model and data dictionary: entities (objects), their attributes, and a class diagram.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Preamble](#11)
2. [Chapter II](#chapter-ii) \
   2.1. [A little Bit about the Life Cycle of An Entity](#21) \
   2.2. [References](#22) \
   2.3. [Object Description](#23) \
   2.4. [Purpose of the Object](#24) \
   2.5. [Object Attributes](#25) \
   2.6. [Class Diagram](#26) \
   2.7. [The Сoncept of Сlass Identification](#27)
3. [Chapter III](#chapter-iii) \
   3.1. [Task 1. Haircut Appointment](#31)
4. [Chapter IV](#chapter-iv) \
   4.1. [Exercise 00 — Persona Class Description](#41) \
   4.2. [Exercise 01 — Description of Clients and Employees Entities](#42) \
   4.3. [Exercise 02 — Description of Reference Entities](#43) \
   4.4. [Exercise 03 — Description of the Service Slots Entity](#44) \
   4.5. [Exercise 04 — Create a Class Diagram](#45) \
   4.6. [Exercise 05 — Description of Discounts for Client, Notification to Client Entities](#46) \
   4.7. [Exercise 06 — Updating the Class Diagram](#47)

## Chapter I <div id="chapter-i"></div>

![Illustration](misc/images/IMG_1719.jpg)

### Preamble <div id="11"></div>

User stories describe the user's view of the system's behavior, and use cases describe the user's interaction with the system. But US and UC do not contain all the information needed to implement the system. 

Programmers do not develop user or business requirements, but entities in the system, their properties and behavior, i.e. functional requirements for the system. The relationship to other entities is usually represented by an Entity-Relationship Diagram (ER diagram or class diagram) in the notation adopted by the team.

In BSA03, you identified the main entities of the domain and built a conceptual model (ER diagram). Continue this work by constructing a logical database (DB) model: a description of the entities and an ER diagram or class diagram.

In this project, you will learn how to describe objects, their structure, and the relationships between them, and how to construct a class diagram. 

Before you start modeling the database structure and designing the objects and functionality of the system, you should brush up on your knowledge of relational databases. You can do this using any book that describes SQL, many courses or training programs, or SQL tutorials on the Internet. For a brief description, see the article [Introduction to Databases](https://habr.com/ru/post/686816/) listed in the Literature section.

**Literature:**

1. Craig Larman "Applying UML and Patterns".
2. Martin Fowler UML Fundamentals. Third Edition.
3. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition, amplified.
4. [Introduction to databases](https://habr.com/ru/post/686816/).
5. Brief description of model notations [entity-relationship (ER diagrams)](https://pro-prof.com/archives/8126).

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

System entities

### 1. A little Bit about the Life Cycle of An Entity <div id="21"></div>

   Actions specified in the US and/or UC or in the business process description are actions on a specific entity entry by users in a specific role.

   To make it easier to track and provide actions on an entity when certain conditions are met, the concept of "entity lifecycle" is used. This is a series of states (statuses) that an instance of an entity goes through under the influence of actions or under certain conditions. To track the status, you add the attribute "Status" to the entity, which defines the state of a particular instance of the entity. You will examine this parameter in detail in the next project, while in this project you will add the attribute to the entity structure when describing entity attributes. 

### 2. References <div id="22"></div>

   Usually, we first consider those entities that carry a semantic load, describe objects. That is, entities, actions on which provide the desired result of business processes. There are also references that describe the data used to fill other entities. So, in our example, we do not specify the name of the service or the name of the master completely in the entities "Slot for service" and "Service booking", but we specify external keys — identifiers of the entity "Services" and the entity "Employee". And by the external key we programmatically retrieve the service name and the full name. This method is used both when the user enters data into the form on the screen and when it is processed in the system.

   The implementation of entities that carry semantic load requires already developed references. Therefore, it makes sense to develop (and describe) references before the main semantic entities. Sometimes other references are needed to implement and use certain references. For example, the Master Services entity uses the Employees and Services references. Therefore, you should start with those that do not use other entities, but on the contrary, are used by other entities.

### 3. Object Description <div id="23"></div>

The description of the object must include:

1. Purpose;
2. Attributes, their description;
3. Relationship of the object to other objects in the system (ER diagram or class diagram);
4. Actions (operations) on object instances;
5. Roles and access rights of these roles (who has the right to perform which actions); 
6. Life cycle of an object instance (states of the instance, conditions for changing the state);
7. Visualization of object instances (user interfaces);
8. Interchange interfaces (integration);
9. Reporting, monitoring, other.

### 4. Purpose of the Object <div id="24"></div>

Here you should briefly (one or two or three sentences) describe the purpose of the entity. What it contains, what business processes it participates in, where the information comes from, what it is used for, where it is transferred to. 

It should be understood that sometimes an object can act as a creating entity (output document) in one business process and as a reference in another. 

For example: Master Services

The object represents the services provided by a particular master. The manager in the system creates records that indicate what services are provided by this or that master. The client selects records (instances) of the object to book the service. 

### 5. Object Attributes <div id="25"></div>

In BSA03, you specified the basic attributes of the entities. For example, in Task 1, the entity "Master Schedule" is defined. Each of its instances (entity records) has specific properties (attributes): date, time, master.

An entity consists of attributes and can contain blocks of attributes. An attribute of an entity is a field (prop) that contains a specific property of the entity. For example, the Employee entity contains the following attributes (fields, props): Last Name, First Name, Patronymic, Current Position. This entity may also contain a block of attributes that describe the history of changes in the employee's position. Analysts determine which attributes are included in the entity based on the task. And, of course, the composition of the attributes may change during team discussions. 

To describe each attribute, you should specify:

- mnemonic (the name by which the entity is identified in the software);
- name of the attribute (in Russian);
- short description (if the name is not enough);
- attribute type;
- whether required or not;
- default value (the value assigned when the field is cleared);
- expected length (if the attribute is textual);
- comments (explanations, conditions).

Mnemonics are often defined by developers according to the rules of a particular programming language. It should be understood that this is the most stable identifier of an entity. Any other attribute, even the name, may change in the course of task development.

Don't add attributes "just in case" if you have doubts and are not sure that the attribute is really needed.

If an entity (object) consists of several blocks, the multiplicity and mandatory nature of the block should be specified when describing the blocks. When creating an ER diagram, blocks are specified as separate classes (objects) related to the original one.

### 6. Class Diagram <div id="26"></div>

Class diagram [(https://ru.wikipedia.org/wiki/%D0%90%D0%BD%D0%B3%D0%BB%D0%B8%D0%B9%D1%81%D0%BA%D0%B8%D0%B9_%D1%8F%D0%B7%D1%8B%D0%BA) is a structural diagram of the [UML](https://ru.wikipedia.org/wiki/UML) that shows the general structure of the hierarchy of system classes, their interactions, attributes (fields), methods, interfaces, and relationships between them.

It is widely used not only for documentation and visualization, but also for construction via forward or reverse engineering.

### 7. The Сoncept of Сlass Identification <div id="27"></div>

1. Identify not specific entities of the physical world, but classes, a generalization of entities. Entities = Classes.
2. Identify entities: identify noun-verb pairs from task descriptions, use cases, requirements, interviews, reports, user stories, and interfaces. All nouns are potential entities or their attributes. Verbs and verb groups are operations that can be performed by or on entities.
3. Principle: Do not create unnecessary entities. Model those aspects of the system that are contained in the requirements.

The class diagram has three sections:

- Top: the name of the class. It is centered and bold. The first letter is capitalized.
- Middle: fields (attributes) of the class. They are left-aligned and the first letter is lowercase.
- Bottom: methods of the class. They are also left-aligned and the first letter is lowercase.

## Chapter IV <div id="chapter-iv"></div>

### Description of tasks

### Task 1. Haircut Appointment <div id="31"></div>

The management of the barbershop chain decided to implement a system that would allow online booking of appointments. The main goal is to develop the business by expanding the client base through the possibility of online registration, as well as to reduce the cost of employee labor and manual labor by automatically informing clients through communication channels.  

Both registered and unregistered visitors can book an appointment on the website. When making an appointment, you can select the type of service: hairdressing or cosmetology, as well as the service itself, the master and the time from the available intervals. The system should provide automatic sending of reminders to clients through the communication channel chosen by the client (Telegram, WhatsApp, VK, SMS) according to the schedule set by the manager. After receiving a service, the system offers the client to evaluate the service and write suggestions on how to improve the work.

The schedule of masters and the services provided by each master should be entered by the manager, who may be more than one person. This person is also responsible for keeping the schedule up to date and adjusting it if necessary, communicating with clients manually, marking the service, charging and accepting payment, sending payment data to the accounting department. The manager can also receive reports on completed services and view client feedback.

Each master has the possibility to view the schedule and appointment for his services, client reviews.

**Terms**

**Slot**: 1 hour time period, initial time is indicated.

**UC01 Register a client (self-registration)**

**Use context:** Client registers to sign up for service.

**Scope:** Barbershop, providing services.

**Level:** User goal.

**Main Actor:** Client.

**Preconditions:** The client has entered the website.

**Main scenario:**

1. The client opens the registration page.
2. The client enters the phone number and name (patronymic).
3. The system confirms that the phone is not registered in the system.
4. The client enters the preferred password.
5. The system announces the password level (weak, medium, high).
6. The system registers the client, sends SMS to the client about registration with name and login.

**Alternative scenario:**

1. The entered phone number is registered in the system:
   1. The system reports that such a phone number is registered in the system.
   2. The client enters another phone number (2.) or refuses to register.

**UC02 Create master schedule**

**Use context:** Manager creates a master schedule in the form of slots for clients to select.

**Scope:** barbershop, providing services to clients.

**Level:** User goal.

**Main actor:** manager.

**Prerequisites:** The manager received a schedule of masters. The manager accessed the website.

**Main scenario:**

1. Manager opens the page for entering master slots.
2. The manager selects a date and a slot (a time period of 1 hour, the start time is indicated), selects a master from the Employees entity, to which the Master role is indicated in the Employee Role entity.
3. The system confirms that the selected slot is not booked in the system by the client.
4. The manager confirms that the time is reserved for the master.
5. The system assigns the slot: date, time, master.

**Alternative scenario:**

1. The selected slot is booked in the system by the client:
   1. The system reports that the selected slot is booked in the system by the client. 
   2. The manager contacts the client by phone and arranges to reschedule the visit to another time or to another master, enters the information into the system. 
   3. The system sends an SMS to the client about the change of time and/or master of the visit.

**UC03 Book a slot**

**Use context:** Client wants to book a barbershop visit.

**Scope:** barbershop, providing services to clients.

**Level:** User goal.

**Main actor:** client.

**Preconditions:** The client has logged into the website.

**Main scenario:**

1. The client opens the slot selection page.
2. The system generates a list of free slots.
3. The client selects a time service slot (date, time) from the free slots.
4. The system generates a list of services that can be selected.
5. The client selects a service from the selectable ones.
6. The system generates a list of masters allowed for selection.
7. The client selects a master from the selectable ones.
8. The system confirms that the selected slot is not booked in the system by another client.
9. The client confirms the slot reservation.
10. The system assigns the slot: date, time, master, service.
11. The system sends a sms to the client about service booking to the phone number specified during registration.

**Alternative scenarios:**

1. Selecting a slot by service:
   1. The client selects a service from the list of services provided by the masters from the Employee Role entity.
   2. The client selects a free service slot by master.
   3. The system shows the free slots in the master's schedule.
   4. The client can view the schedule.
   5. Client selects a slot from the free slots.
   6. The system sends an SMS to the client's phone number about the slot reservation.

**UC04 Register Client (Manager)**

**Use context:** A manager, when communicating with a client over the phone, registers the client to book a service.

**Scope:** barbershop, providing services to clients.

**Level:** User goal.

**Main actor:** Manager.

**Preconditions:** A client called the manager. The manager accessed the barbershop's website.

**Main scenario:**

1. The manager opens the client registration page.
2. The manager enters the phone number and name that the client provided over the phone.
3. The system confirms that the phone is not registered in the system.
4. The system registers the client, generates a temporary password, sends a sms to the client's phone about registration with name, login, temporary password.

**Alternative scenario:**

1. The entered phone is registered in the system:
   1. The system informs that such phone number is registered in the system.
   2. Client enters another phone number (2.) or refuses to register.

## Chapter V <div id="chapter-v"></div>

### Exercise 00 — Persona Class Description <div id="41"></div>

For Task 1, describe the Persona class: 

1. Specify the purpose of the Persona class based on the task description and UCs;
2. Define attributes (as a minimum):
   1) identifier of the Persona;
   2) registration data for access to the system (login, password);
   3) name, (patronymic) — for addresses;
   4) phone number — for sending sms and calls;
   5) date of registration.
3. Specify for attributes:
   1) name,
   2) key (primary, external — if any),
   3) data type,
   4) length limitation for text data,
   5) whether it is required or not,
   6) <a name="_heading=h.1fob9te"></a>default value,
   7) comments.

### Exercise 01 — Description of Clients and Employees Entities <div id="42"></div>

For Task 1, describe the entities Clients, Employees, for each entity:

1. Specify the purpose of the entities according to the application in UC and the description in the task.
2. Define the attributes (as a minimum):
   1) record identifier (primary key),
   2) persona entity identifier (foreign key),
   3) the date of the record.
3. For attributes, specify:
   1) name,
   2) key (primary, external — if any),
   3) data type,
   4) for text data — length limitation,
   5) whether it is required or not,
   6) default value,
   7) comments.

### Exercise 02 — Description of Reference Entities <div id="43"></div>

For Task 1, describe the reference entities that will provide the implementation of UC01, UC02, UC03:

- Employee Roles;
- Services;
- Master Services.

For each entity, describe:

1. Specify the purposes of the entity.
2. Define the attributes of the entity:
   1) Employee Roles:
      1) record identifier,
      2) employee — identifier of the entity Employees,
      3) role (list of values: master, manager).
   2) Services:
      1) record identifier,
      2) name of the service.
   3) master services:
      1) record identifier,
      2) employee identifier — foreign key to the Employees entity,
      3) service identifier — foreign key to the Services entity.
3. Specify for attributes:
   1) name,
   2) data type,
   3) length limitation (for text data),
   4) whether it is require or not,
   5) default value/empty value,
   6) comments.

### Exercise 03 — Description of the Service Slots Entity <div id="44"></div>

For Task 1, describe the essence of Service Slots:

1. Specify the purpose.
2. Define attributes as a minimum:
   1) record identifier,
   2) date,
   3) slot start time,
   4) master (foreign key to the Employees entity),
   5) client (foreign key to the Clients entity).
3. Define attributes, specify:
   1) name,
   2) data type,
   3) length limitation (for text data),
   4) whether it is require or not,
   5) default value,
   6) comments.

### Exercise 04 — Create a Class Diagram <div id="45"></div>

For Task 1, create a class diagram in UML notation.

1. Place in the diagram the classes specified in Ex. 00 to Ex.03.
2. Specify the classes in UML notation:
   1) name — at the top, bold, the first letter is capitalized;
   2) attributes — in the middle part, left-aligned, the first letter is capitalized;
   3) methods — not specified.
3. Specify primary and foreign keys.
4. Identify relationships between classes, describe with semantic words.
5. Specify cardinality on the relationships: 1:1, 1:\*, \*:1.

### Exercise 05 — Description of Discounts for Client, Notification to Client Entities <div id="46"></div>

For Task 1, describe Discounts for Client, Notification to Client entities.

1. Specify the purpose.
2. Identify the attributes.
3. Define and specify attribute parameters.

### Exercise 06 — Updating the Class Diagram <div id="47"></div>

For Task 1, add the Discounts for Client, Notification to Client entities to the class diagram.
