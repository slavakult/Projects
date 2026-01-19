# Designing functional requirements

Summary:
In the current project, you will continue to design the functionality of the system and learn what aspects should be specified so that the developers can implement the functionality correctly.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Preamble](#11)
2. [Chapter II](#chapter-ii) \
   2.1. [Operations with an Object (Object Instance)](#21) \
   2.2. [Specifics of Operations](#22) \
   2.3. [Example Analysis](#23) \
   2.4. [Roles, Role Model, Access Rights](#24) \
   2.5. [Life Cycle of an Entity](#25) \
   2.6. [Checks](#26)
3. [Chapter III](#chapter-iii) \
   3.1. [Task 1. Haircut Apointment](#31)
4. [Chapter IV](#chapter-iv) \
   4.1. [Exercise 00 — Identifying Objects that have a Status Model](#41) \
   4.2. [Exercise 01 — Life Cycle of the Service Slots](#42) \
   4.3. [Exercise 02 — Status Models of Entities](#43) \
   4.4. [Exercise 03 — Description of Actions on References](#44) \
   4.5. [Exercise 04 — CRUD Operations on the Service Slots Object](#45) \
   4.6. [\*Exercise 05 — Detailed Operations on the Service Slot Object](#46) \
   4.7. [\*Exercise 06 — Role Access Rights](#47)

## Chapter I <div id="chapter-i"></div>

![Illustration](misc/images/IMG_1718.jpg)

### Preamble <div id="11"></div>

In the previous projects, BSA03 and BSA09, you identified domain entities, created database objects (classes), basic attributes of classes, and their properties. You specified relationships between classes, built a logical data model, and described a data dictionary. In the current project, you will describe operations on the objects. System users perform their tasks by performing operations on the data they contain (on instances of classes).

### Literature

1. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition, amplified.
2. Alan Cooper, Robert Reimann, David Cronin “About face. The essentials of interaction design”.
3. Y. Kupriyanov "[Requirements don't change, you're the one who failed to identify them. 10 techniques for checking the completeness of requirements](https://conf.uml2.ru/class/trebovaniya-ne-menyayutsya-eto-vy-ikh-nedovyyavili--10-tekhnik-proverki-polnoty-trebovanii.html)" LAF, 2018.
4. https://rutube.ru/video/c8eacc767b438bc228cca1a5708dd43e/?ysclid=m0m8lolag1812195071

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

Each user group (role) performs its own actions. The user's view of the system's behavior in response to their actions is described in UC, specified in US. For example, a manager enters a master schedule ("service slot") into the system, and a client selects a particular record (instance) of this object from the schedule to book a service. That is, the system allows the manager to add/edit the schedule, save it, show it to the client, and the client selects a slot. Analyst based on business process diagrams and descriptions, UC and US describe the functionality. This is what you will do in the current project.

### 1. Operations with an Object (Object Instance) <div id="21"></div>

When considering and describing operations with an object, you should consider:

1) creating (CREATE) a new record;
2) editing (UPDATE) an existing record or prohibiting editing;
3) reading (READ) a record, including using the object to select a value from a list (from a reference or classifier) when creating/editing another entity;
4) deleting (DELETE) or prohibiting deletion.

In addition, you should consider, select and describe what is needed:

1) confirmation of execution, rollback of the operation (if it is necessary, under what conditions); 
2) form of visualization of the object (list and/or card);
3) participation of the object in integration (import or export from/to another system);
4) saving the history of changes (when and what to save);
5) transfer of records to the archive (who transfers them, under what conditions);
6) other operations (calculations, checks);
7) operations that cause changes in other parts of the system (sending SMS or other messages, changing the status of another object, logging);
8) operations with other objects that change something in ours.

Use the following table to make sure that all operations with objects are described:

|                 | CREATE |      | READ |      | UPDATE |      | DELETE |      |
| --------------- | ------ | ---- | ---- | ---- | ------ | ---- | ------ | ---- |
|                 | Role   | UC   | Role | UC   | Role   | UC   | Role   | UC   |
| Clients         |        |      |      |      |        |      |        |      |
| Employees       |        |      |      |      |        |      |        |      |
| Employee Roles  |        |      |      |      |        |      |        |      |
| Services        |        |      |      |      |        |      |        |      |
| Master Services |        |      |      |      |        |      |        |      |
| Service Slots   |        |      |      |      |        |      |        |      |

If there is no role that receives information (reads), then check, maybe this object is unnecessary.

The same table can be continued for other actions with objects:

1. form of visualization of the entity (list and/or card),
2. confirmation of execution,
3. rollback of the operation,
4. sorting,
5. filter,
6. search,
7. logging of operations,
8. sending messages.

For additional parameters on these operations, see the Y. Kupriyanov's speech "[Requirements don't change, you're the one who failed to identify them. 10 techniques for checking the completeness of requirements](https://conf.uml2.ru/class/trebovaniya-ne-menyayutsya-eto-vy-ikh-nedovyyavili--10-tekhnik-proverki-polnoty-trebovanii.html)", ЛАФ, 2018 г.  

### 2. Specifics of Operations <div id="22"></div>

**Deletion, editing**

You should be careful with the deleting/editing of a record. In some cases, deleting a record in one object can cause errors in other objects. For example, if a master has resigned, what should happen to the instances of the Employee and Master Services objects? Can they be deleted? What changes should be made to the instance of the Service Slot object? In case of replacing the master in the schedule — what to do with the record of the client who has already registered with the required master? Such questions should be considered, first of all, from the point of view of business and user behavior to determine what changes should occur in the entity in the subject world. If necessary — make changes in business process diagrams, US and UC. And then clarify the operations on the entity. To understand the problem — study cascading delete / edit in relational database https://habr.com/ru/post/194738/.

**Use of References**.

There is an important nuance to using references. Sometimes reference records become irrelevant, but they still cannot be deleted. As in the example above, a master has left his job and can no longer be assigned a service. If you delete the record about him from the employee reference, you will lose the information about the services previously performed by this master. In order not to lose this information, one of the two methods or a combination of them is used:

1. Add the Archive feature to the references, which indicates that this reference record cannot be used for assigning services or selecting a master in the future, and is valid only for the services already assigned.
2. Specify the start and end date of the record's relevancy. This is the period during which the record can be used for assigning services.

If these attributes (archive or start and end date of record relevance) are not present in the reference entity, they should be added depending on the chosen implementation option.

So how do we not miss those cases where implicit cases should be considered? At least — when there is a relationship with another entity using a foreign key.

### 3. Example Analysis <div id="23"></div>

Let's look at the example of a master leaving. His work schedule has been entered in the Service Slot for a long time. Clients have already been registered to him.

Since the master is retiring, it can no longer provide services. That is, the records corresponding to this master should be deleted (or marked inactive) from the master's Services object and the Service Slot object. However, the Service Slot object already contains records of clients who have been with the retiring master for some time. Deleting the master's records will result in the loss of the client visit recorded for some time. This means that before deleting a master record from the Employee object (or marking it as quit), we need to contact the client and discuss rescheduling the service to another master and/or another time. Or, replace the master's designation in the slot (replace the master in the schedule) and send a message to the client about replacing the master.

All of the above actions should be added to UC and, if necessary, attributes should be added to the corresponding database classes. For example, the date of resignation in the Employee object or attribute characteristics, mandatory attribute ID of the master in the Service Slot object.

### 4. Roles, Role Model, Access Rights <div id="24"></div>

The list of user roles that interact with the system was developed by you in the onion and context diagrams and created in the BSA02 project. It is possible that during the development of the diagrams, US or UC, something has changed, roles have been added, deleted or renamed. Therefore, you should check and update the roles if necessary, and specify the actions of the roles through the system objects. The following table (short version) describes the access rights of roles to objects according to their functions. For example, if the role functions include creating, reading, and correcting references, the role should have the right to create, read, and correct an object instance. An example of specifying the access rights of a user in the Client role to the Clients object is shown in the table below. 

| Objects |            | Roles                                                        |         |        |       |
| ------- | ---------- | ------------------------------------------------------------ | ------- | ------ | ----- |
|         |            | client                                                       | Manager | Master | Admin |
| Clients | С (CREATE) | record only in person                                        |         |        |       |
|         | R (READ)   | record only in person                                        |         |        |       |
|         | U (UPDATE) | record only in person                                        |         |        |       |
|         | D (DELETE) | record only in person and if there are no service appointments |         |        |       |

### 5. Life Cycle of an Entity <div id="25"></div>

Some system objects have a complex life cycle in one or more business processes. To make it easier to work with such objects, the concept of life cycle is used. Each instance of this object passes through a number of states, from creation to completion, through development, maturity, and retirement. The names of these states (statuses) are usually assigned in terms of the domain. The format of the status model description can be either a state transition diagram or a table (K. Wiegers, "Software Requirements" 3rd edition, chapter 12). A textual description is found in production rules. 

A diagram has the advantage of being easier to visualize and to detect inaccuracies. However, it is not always convenient to specify everything needed for development on the diagram. Therefore, if necessary, they are described additionally. This is important for developers to understand:

1. the initial state;
2. who the initiator/executor is;
3. what actions are being performed;
4. if there are conditions, if checks are required; 
5. what state is being transitioned to (under what conditions).

### 6. Checks <div id="26"></div>

Checks are often needed in a business process. They may be required when data is entered (manually or imported), before transferring to another system, or when changes are made in another object. The checks can be specified both in the business process description and in the UC or can be identified separately by the analyst. The description of checks should contain:

1. the operation and its relationship (before or after) which the check is performed;
2. the attribute or combination of attributes to be checked;
3. a description of the check;
4. criticality;
5. error message, where to output;
6. what should be done (stop processing, continue checking, generate and record an error message, change the record status, etc.).

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
5. The system informs the password level (weak, medium, high).
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

## Chapter V <div id="chapter-v"></div>

### Exercise 00 — Identifying Objects that have a Status Model <div id="41"></div>

For Task 1, identify entities that require a life cycle description.

1. Identify entities that change their state during the course of working with the system.
2. Identify entities that depend on their state to work with the system. 
3. Identify entities for which it makes sense to monitor life cycle stages.
4. Provide a rationale for each entity for which you plan to monitor the lifecycle.
5. Add a Status attribute to each entity, and update the entity attribute description.
6. Present the result in a tabular format.

### Exercise 01 — Life Cycle of the Service Slots <div id="42"></div>

For Task 1, develop a status model of the Service Slots object.

1. Define object states from creation to service fulfillment according to UCs. 
2. Form the names of the object statuses with verbal nouns or participles.
3. Provide the state of canceling the service at the initiative of the client.
4. Provide the state of not providing the service at the initiative of the barbershop.
5. Verify that UCs have client-initiated canceling and barbershop-initiated failure to provide service. 
6. Refine UCs in terms of specifying the change of object status, place it in the task.
7. Develop a diagram of the states of the object Service Slot.
8. Specify on the diagram the executor, actions to be performed and conditions when changing the status of the object.
9. Place the diagram in the task. 

### Exercise 02 — Status Models of Entities <div id="43"></div>

For Task 1, develop status models for the objects defined in Ex.00, except for the Service Slots object.

1. Define the statuses during the life cycle.
2. For each status, specify:
   1. name (verbal noun or participle);
   2. initial state / status;
   3. initiator / executor / initiating event;
   4. what actions are being performed;
   5. whether there are conditions, whether checks are needed; 
   6. what state is transitioned to (under what conditions).
3. Specify the beginning and end of the lifecycle.
4. Present in tabular form, possibly with additional description.

### Exercise 03 — Description of Actions on References <div id="44"></div>

Describe the functionality of the references of Task 1:

1) Clients,
2) Employees,
3) Employee Roles,
4) Services,
5) Master Services.

1. For each reference and action, specify:
   1) The role performing the action;
   2) The UC where the action is described.
   3) Actions on the references:
      1) creating records;
      2) reading records;
      3) updating records;
      4) deleting records.
   4) For each references/operation, specify:
      1) execution conditions;
      2) whether rejection is possible, under what conditions;
      3) whether confirmation is required;
      4) generating changes in other parts of the system;
      5) logging (if required) and what to log;
      6) notification (to whom and how, if required).

### Exercise 04 — CRUD Operations on the Service Slots Object <div id="45"></div>

For Task 1, define the basic actions on the Service Slots object.

1. Specify the roles in the section of CRUD actions on the object.
2. Verify the existence of CRUD actions in UC by role. 
3. If necessary:
   1. supplement/clarify the UC;
   2. place UC in the task;
   3. color-code the addition/clarification.
4. Indicate the UCs in which the relevant actions are described.
5. Place in tabular form (see section 4 above).

### Exercise 05 — Detailed Operations on the Service Slot Object <div id="46"></div>

For Task 1, define additional actions on system objects.

Continue the table of CRUD actions on objects, specify:

1. form of entity visualization (list and/or card);
2. confirmation of execution;
3. rollback of the operation; 
4. sort;
5. filter;
6. search;
7. logging of operations;
8. sending messages.
9. Place in tabular form similar to the table of CRUD actions on objects.

### Exercise 06 — Role Access Rights <div id="47"></div>

For Task 1, describe the access rights of roles to objects.

1. Define access rights to objects:
   1. Clients,
   2. Employees,
   3. Roles of the employee,
   4. Services,
   5. The services of the foreman,
   6. Service slot.
2. Define access rights for each role:
   1. Manager,
   2. Master,
   3. Client,
   4. Administrator.
3. Describe the access rights of CRUD operations.
4. Specify access conditions for each role to each object.
5. Specify what changes must be made to other parts of the system.
6. Determine and specify whether notification of the operation is required, who to notify, how to notify.
7. Determine and specify whether operation logging is required, what parameters to log.
8. Provide for denial of access to operations to eliminate uncertainties.
9. Provide deletion operation only for the role of Administrator and for absent during the year service records for the master, service, client. 
10. Place in tabular form. 
