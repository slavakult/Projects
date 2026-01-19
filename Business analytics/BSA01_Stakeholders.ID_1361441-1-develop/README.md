# Interested Parties (Stakeholders)

Summary:
Today you will learn who stakeholders are and what their importance is to IT systems, as well as techniques for identifying stakeholders and methods of working with them.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Preamble](#11)
2. [Chapter II](#chapter-ii) \
   2.2. [General Rules](#21)
3. [Chapter III](#chapter-iii) \
   3.1. [Interested Parties](#31) \
   3.2. [Who's interested in the system?](#32) \
   3.3. [Roles](#33) \
   3.4. [Stakeholder Directory](#34) \
   3.5. [Onion Diagram](#35)
4. [Chapter IV](#chapter-iv) \
   4.1. [Task 1. Haircut Appointment](#41) \
   4.2. [Task 2. Delivery of Orders](#42)
5. [Chapter V](#chapter-v) \
   5.1. [Exercise 00 — Identification of Stakeholders](#51) \
   5.2. [Exercise 01 — Building a Stakeholder Onion Diagram ](#52) \
   5.3. [Exercise 02 — Interests, Needs, Problems of Stakeholders](#53) \
   5.4. [Exercise 03 — Completing the Glossary](#54)

## Chapter I <div id="chapter-i"></div>

![](misc/images/Illustration_01.jpg)

### Preamble <div id="11"></div>

Every system (industrial, intellectual, cultural or IT) is built in someone else's interest, to meet someone else's needs. It's good to remember Tom Gilb's words: "There is always one more stakeholder than you know about; and the known stakeholders have at least one more need than you know about now". In this project you will learn how to identify stakeholders and their needs. 

**Literature:**

1. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition.
2. BABOK v3 «A Guide to the Business Analysis Body of Knowledge» IIBA.
3. [Stakeholders: an area of special attention](https://habr.com/ru/post/127630/).
4. [Who are stakeholders and how to manage them](https://blog.calltouch.ru/stejkholdery-kto-eto-takie-kakie-byvayut-vidy-stejkholderov-proekta/).

## Chapter II <div id="chapter-ii"></div>

### General Rules <div id="21"></div>

1. Along the way, you may feel a sense of uncertainty and a severe lack of information: that's OK. Remember, the information in the repository and on Google is always with you. So are your peers and Rocket.Chat. Communicate. Search. Use common sense. Don't be afraid to make mistakes.
2. Pay attention to sources of information. Check. Think. Analyse. Compare. 
3. Look at the text of each assignment. Read it several times. 
4. Read the examples carefully. There may be something in them that is not explicitly stated in the task itself.
5. You may find inconsistencies where something new in the terms of the task or examples conflicts with something you already know. If you come across such an inconsistency, try to work it out. If not, write it down as an open question and find out as you work. Do not leave open questions unanswered. 
6. If a task seems confusing or impossible, it only seems that way. Try to break it down. It is likely that some parts will become clear. 
7. There will be various tasks. Those marked with an asterisk (\*) are for the more meticulous students. These tasks are more difficult and are not compulsory. But doing them will give you extra experience and knowledge.
8. Don't try to fool the system or the people around you. You will fool yourself first.
9. Got a question? Ask your neighbour to the right. If that doesn't help, ask your neighbour on the left.
10. When you use help, you should always understand why and how. Otherwise the help is useless.
11. Always push only to the develop branch! The master branch will be ignored. Work in the src directory.
12. There should be no files in your directory other than those specified in the tasks.


## Chapter III <div id="chapter-iii"></div>

### 1. Stakeholders <div id="31"></div>

If a system does not bring value to the person in whose interest it is created/changed, then it is not needed.
So the first question to answer is:

### 2. Who's interested in the system? <div id="32"></div>

People or organizations that have an interest in the system in one way or another are called interested parties (stakeholders). 

Stakeholders are one of the key concepts of business analysis. A significant part of IT business analysis is devoted to identifying stakeholders and their needs, as well as creating requirements to meet those needs.

**Interested parties (Stakeholders)** is a group of individuals and/or one person who can:

- influence the system;
- to be influenced by the system;
- feel influenced by the system;
- influence the choice of how the system is implemented.

Stakeholders are therefore those who are affected by the system in one way or another, or who believe that the system affects their interests. They are also those who influence or can influence the system. This influence and impact can be either in the development or in the use of the system.

It is therefore important to identify the stakeholders (individuals or groups) and define their needs. Identify the requirements that will enable the system to meet these needs.

Stakeholders groups may include:

1. Those who order and pay for the project: owners, investors, customers; 
2. Those who produce or provide goods or services for further distribution or application by the system: suppliers, intermediaries, producers;
3. Those who receive goods or services through the system: buyers, clients;
4. Those who set and monitor the rules and regulations for the operation of the system, the regulators: public authorities or institutions;
5. Competitors — they are not always interested in making the system work, or work well, and can therefore negatively influence its design and operation;
6. Those who keep the system running and provide support to system users: administrators, support specialists.

There are many techniques for working with stakeholders. In this project we will consider:

1. Directory (list) of stakeholders; 
2. Onion diagram.

### 3. Roles <div id="33"></div>

Each of the above groups is defined by their interests in relation to our system. 

Some stakeholders can be grouped together because they perform the same functions in the system. Such groups are called roles (project role, role in the project). 

A role is named after the primary function it performs. For example, a person who selects a product, adds it to the shopping cart, pays for it, and receives it in one way or another is a Buyer. 

It is not recommended to call a project role by generalized names that collect several roles, including those that perform different functions (e.g. User), if there are separate groups that perform different functions in the system: buyers, sellers, merchandisers, accountants. 

Each stakeholder (organization or person) can perform several roles, e.g. a customer can also be a supplier, i.e. if a supplier of goods/services has ordered the system to promote his goods/services, he is both a customer and a supplier. And a role can be played by several stakeholders (i.e. having the same interest, performing the same functions in the system). 

And sometimes a natural person (and even an organization) may, under the influence of circumstances, change its interests and the actions it performs, i.e. change its role in the project.

### 4. Stakeholder Directory <div id="34"></div>

In order to identify all possible sources of requirements and not lose their needs, a stakeholder directory should be created and maintained during the system development process. Stakeholders can be identified not only at the beginning of the project, but also later on. An up-to-date stakeholder register is needed throughout the project to avoid losing important stakeholders. It can include users of the system as well as those who are interested in the system but do not work with it.

In order to analyze the importance of stakeholders for the project and to choose ways of working with them, it is recommended to collect such characteristics in a directory:

1. Full name (if known); 
2. Contact information (phone number, email, nickname in social networks where you have agreed to communicate);
3. Organization/Company;
4. Position;
5. Location;
6. Role in project (if clear);
7. Role scalability (one/approximate number);
8. Responsibility in the project (what is responsible for);
9. Level of authority in the project (what is authorized to do/decide);
10. Previous experience useful to the project;
11. Date the stakeholder was added to the directory.

In the case of a small project, it is sufficient to select 2-4 characteristics that will help you work with stakeholders, for example, to organize stakeholders into areas of the onion diagram (see Section 5. Onion Diagram) and to define the role of users in the system. 

There are several questions that can help you identify stakeholders. 

Table 1. Stakeholder groups and questions to identify them

|      | Class                                              | Questions                                                    |
| ---- | -------------------------------------------------- | ------------------------------------------------------------ |
| 1    | Beneficiaries     (employers, sponsors, investors) | Who orders the system? Who pays for the development of the system? Who is interested in the income from the project? |
| 2    | Users (buyers, customers, sellers, etc.)           | Who will use the system?                                     |
| 3    | Interacting parties                                | With whom does the system interact? With whom does it integrate? |
| 4    | Competitors                                        | Does the system have competitors? Who are they?              |
| 5    | Regulators                                         | What laws and regulations should the system be based on?     |
| 6    | Support team                                       | Who will keep the system running while it is in use? Who provides access? Who recovers the system from failures? Who consults with users? |
| 7    | Development and implementation team                | Who prepares the initial data? Who corrects errors, develops the system? |

### 5. Onion Diagram <div id="35"></div>

The onion diagram helps to identify stakeholders, their relationship to the product, their interests and needs. The elements (stakeholders and stakeholder groups) are shown in concentric circles, the elements in each circle are at the same distance from the system: they depend on it (use the results or data), are external to it but interact with it (receive or transmit information to it).

![](misc/images/img1_eng.png)

## Chapter IV <div id="chapter-iv"></div>

### Task 1. Haircut Appointment <div id="41"></div>

The management of a chain of barbershops decided to implement an online booking system. The main objective is to develop the business by expanding the customer base through the possibility of online registration, as well as to reduce employee labour costs and manual labour by automatically informing customers through communication channels.

Both registered and unregistered visitors can book an appointment on the website. When making an appointment, they can select the type of service: hairdressing or cosmetology, as well as the service itself, the master and the time from the available intervals. The system should provide automatic sending of reminders to clients through the communication channel chosen by the client (Telegram, WhatsApp, VK, SMS) according to the schedule set by the manager. After receiving a service, the system offers the client to evaluate the service and write suggestions on how to improve the work.

The schedule of masters and the services provided by each master should be entered by the manager, who may be more than one person. This person is also responsible for keeping the schedule up to date and adjusting it if necessary, communicating with customers manually, marking the service, charging and accepting payment, sending the payment data to the accounting department. The manager can also receive reports on completed services and view customer feedback.

Moreover, the system must ensure that the sanitization of the premises of each barbershop is recorded, as required by the Sanitary and Epidemiological Inspectorate. The sanitization schedule is set by the manager, who also marks the completion after sanitization by the technician.

Each master has the possibility to see the schedule and the date of his services, as well as the clients' reviews.

### Task 2. Delivery of Orders <div id="42"></div>

During the lockdown, many grocery stores and food companies dramatically increased their online sales and the need for quick delivery of small quantities to individual customers increased. 

A group of students got together and decided to create a delivery service startup. 

The idea is to quickly receive information about orders, pickup location and time, delivery location, desired delivery dates, and distribute this information to couriers who will pick up the order at the pickup location and deliver it to the delivery location. They decided to develop an online system where orders could be collected and quickly sorted for delivery by couriers. The first step was to collect orders from stores and caterers in any way possible and have the operator enter them into the system in a consistent format, as well as developing a mobile application for the courier. 

The courier should be able to view order information, select an order from those available, book it, pick it up at the collection point and deliver it to the customer. The result of the courier's actions should be immediately reflected in the system via a mobile application. The system should also include a dispatcher who controls the couriers and reassigns orders if necessary. Information on received orders should be sent to the accounting department (to another IT system) to calculate delivery charges with order suppliers. Order delivery information should also be sent to the accounting department to calculate payment to couriers. Accrued payment should be transferred to the system and displayed in the courier's personal account. And there should also be an administrator's workplace, where couriers are registered and access rights are assigned to all of them.

## Chapter V <div id="chapter-v"></div>

### Exercise 00 — Identification of Stakeholders <div id="51"></div>

**For task 2:**

1. Create a stakeholder directory.
2. List stakeholders in the directory.
3. Define the directory characteristics, i.e. the categories by which the stakeholders of each task will be classified. Specify the characteristics known from the task conditions.
4. Indicate your answers in the turn-in file ex00\_<product prefix>\_stakeholders.xlsx.

**Recommendations for the task:**

1. Select the categories you need:
   - Categorize by onion diagram area for future work;
   - Identify roles in the system.
2. Select directory categories based on the context of the task. You may want to consider the list of stakeholder groups described in the "Who is interested in the system?".
3. Specify stakeholders in the directory.
4. Rank the categories based on the conditions of the task.
5. Enter the date the stakeholder was added to the directory. It should be a project number (example: BSA 01).
6. An example of part of the stakeholder directory for Task 1 is shown in the table below.

**Stakeholder Directory** using Task 1 as an example.

| Identifier | Stakeholder's Full name (if known) | Organization or Natural person | Stakeholder Category | Level of contact with the system (onion diagram) | Role in the project (if any) |
| ---------- | ---------------------------------- | ------------------------------ | -------------------- | ------------------------------------------------ | ---------------------------- |
| st00100    | Head of the chain                  | Organization                   | System organization  | Doesn't communicate with the system              | None                         |
| st00200    | Registered visitor                 | Natural person                 | Affected parties     | End user                                         | Сlient                       |
| st00300    | Unregistered visitor               | Natural person                 | Affected parties     | End user                                         | Visitor                      |
| st00400    | Master                             | Natural person                 | Affected parties     | End user                                         | Master                       |
| st00500    | Manager                            | Natural person                 | Affected parties     | End user                                         | Manager                      |
| st00600    | Administrator                      | Natural person                 | Affected parties     | End user                                         | Administrator                |
| st00700    | SEI                                | Organization                   | Regulator            | Affected external parties                        | Adjacent system              |
| st00800    | System developers                  | Organization                   | Project team         | Create a system                                  | Developers                   |


### Exercise 01 — Building a Stakeholder Onion Diagram <div id="52"></div>

**For task 2:**

1. Define stakeholder categories in terms of interaction with our system (Onion Diagram layers). Define one of the categories as an attribute of the onion diagram layer.
2. Identify stakeholders or groups (roles) related to each category (layer).
3. Create an Onion Diagram, indicate the layers and stakeholders related to each layer.
4. In addition, specify those stakeholders that are not specified in the task, but may be common in life.
5. When identifying stakeholders that are not in the directory, add them to the directory of Ex. 00.
6. Enter your answers in the turn-in file ex01\_<product prefix>\_onion.xxx (xxx — extension).

**Recommendations for the task:**

Build an onion diagram. Here is an example of onion diagram for task 1: 

![](misc/images/img2_eng.png)

### Exercise 02 — Interests, Needs, Problems of Stakeholders  <div id="53"></div>

**Fpr each task:**

1. Write down in a table the interests, needs, problems of stakeholders (including external stakeholders).
2. Indicate your answers in the turn-in file ex02\_<product prefix>needs.xlsx.

**Recommendations for the task:**

Here in the table is an example of description of interests, needs, problems of a key stakeholder for task 1.

| Ident.  | Stakeholder                  |      | Interests               |      | Needs                                                        |      | Problems                                                     |
| ------- | ---------------------------- | ---- | ----------------------- | ---- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| st00100 | Head of the barbershop chain | 1    | Business volume         | 1    | Expand the client base                                       | 1    | Lack of client base growth                                   |
|         |                              | 2    | Size of the client base | 2    | Increase the average check                                   | 2    | Clients by appointment don't reach the services              |
|         |                              | 3    | Employees' labor costs  | 3    | Reduce the labor costs of employees for calling and making appointments for clients | 3    | High uneven labor costs (peak periods) for phone bookings,   |
|         |                              | 4    | Average check           | 4    | Reduce errors when making appointments for services over the phone | 4    | Clients are often unable to make an appointment over the phone |
|         |                              |      |                         | 5    |                                                              | 5    | During peak periods, the manager has no time to handle calls for appointments |
|         |                              |      |                         | 6    |                                                              | 6    | The client often doesn't show up for the service, doesn't remember the time of the appointment |
|         |                              |      |                         | 7    |                                                              | 7    | Clients do not see a full list of services when making an appointment over the phone |

### Exercise 03 — Completing the Glossary <div id="54"></div>

**For each task:**

1. Write down new concepts and terms found in the task into a glossary. 
2. Find descriptions of concepts and terms and write them in a glossary. 
3. Indicate your answers in the turn-in file ex03\_<product prefix>glossary.xlsx.
