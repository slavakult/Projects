# User Stories

Summary:
In this project, you will study User Stories (US), understand their benefits, learn how to create them and their associated acceptance criteria and test scenarios. You will also discuss user stories with others involved in the development process and understand the positive outcome of the discussion.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

1. [Chapter I](#chapter-i) \
   1.1. [Preamble](#11)
2. [Chapter II](#chapter-ii) \
   2.1. [General Rules](#21)
3. [Chapter III](#chapter-iii) \
   3.1. [User Stories](#31)
4. [Chapter IV](#chapter-iv) \
   4.1. [Task 1. Haircut Appointment](#41) \
   4.2. [Task 2. Delivery of Orders)](#42)
5. [Chapter V](#chapter-v) \
   5.1. [Exercise 00 — Description of User Stories](#51) \
   5.2. [Exercise 01 — Description of User Stories](#52) \
   5.3. [Exercise 02 — User Stories Coordination](#53)

## Chapter I <div id="chapter-i"></div>

![](misc/images/Illustration_07.jpg)

### Preamble <div id="11"></div>

A user story is a short, concise description of a value to the user and the functionality (or quality of the system) required to achieve the desired value. User stories can be used as a basis for identifying user needs in a system. They are also used for:

- documenting;
- prioritization of functionality;
- evaluating and planning the solution supply;
- a framework for creating acceptance tests.

### Literature

1. Jeff Patton "User Stories. The Art of Agile Software Development".
2. Mike Cohn “User Stories Applied. For Agile Software Development”.
3. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition, amplified.
4. BABOK v3 "A Guide to the Business Analysis Body of Knowledge" IIBA.
5. Dean Leffingwell, Don Widrig "Managing Software Requirements".

## Chapter II <div id="chapter-ii"></div>

### General Rules <div id="21"></div>

1. Along the way, you may feel a sense of uncertainty and a severe lack of information: that's OK. Remember, the information in the repository and on Google is always with you. So are your peers and Slack. Communicate. Search. Use common sense. Don't be afraid to make mistakes.
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

### 1. User Stories <div id="31"></div>

***UserStory*** (US) is a method for quickly understanding and briefly documenting the needs of the users of a system. A brief description of the functionality and/or quality required by a particular stakeholder to achieve expected benefits. 

US is one or two sentences on a small card (sticker). US does not contain everything there is to know about a stakeholder's need. US helps to identify the most important stories and to prioritize the results of the functionality. It becomes clear what should be discussed, worked on in detail, and developed first. Information is added during the discussion and implementation process.
Tools used: stickerboard, miro, trello, … jira, confluence, any text editor.

US must be:
- short,
- simple,
- valuable (fill a need), 
- atomic (a feature or quality),
- business-like (described in business or user terms).
  You can read more about US in Jeff Patton's book "User Stories. The Art of Agile Software Development" and Mike Cohn's "User Stories Applied. For Agile Software Development.

***US Description***\
US Composition:

- header,
- body,
- acceptance criteria,
- test scenarios.

*Header* describes the action the user wants to perform using the system. It is usually an active verb phrase of the goal.

* US Body Format:* **As** [*user role*], **I want/can** [*do this and that*] **to** [*gain some benefit*].\
  *Example:* "I, as a cinema viewer, want to buy a ticket online in advance to see the movie at a convenient time."

***Acceptance Criteria:***
US is usually accompanied by the development of acceptance criteria. Acceptance criteria define the boundaries of the story and provide insight into what behavior or quality the solution must provide in order to deliver value to the stakeholder. 

*Composed of:*
- *Preсondition (Given)* — the user's role, circumstances;
- *Action (Trigger) (When)* — some action is carried out by the user with the help of the system;
- *Result (Then)* — why, what value to get.

*Format:*
Given [*precondition*], when [*a specific action is performed*], then [*a result must occur*].\ 
For example: "When I buy a cinema ticket online, then I can buy a ticket for a session given my free time".

***Test Scenarios:***
A test scenario is a description of what is supposed to be tested. What data, what settings, what actions should be performed during the test. And what is the expected result. \
For example:
- *Precondition:* the user is registered in the cinema network (has an online account). The user has selected a movie and date.
- *Action:* the system displays available sessions. The user selects a session, views the available seats, and selects an available seat in the cinema.
- *Expected result:* the system prompts the user to pay for the ticket.

***US Advantages:***

- Small implementable and testable pieces of functionality;
- Easy for stakeholders to understand;
- Focus on benefit, value, allows for better process understanding.

***US Disadvantages:***

- Requires understanding of context and seeing the big picture;
- Generally cannot provide documentation sufficient for implementation;
- Intended for quick and short-term fixes, not for long-term storage.

***Recommendations for US:***

1. Describe US in the following order:
   1. user role, preconditions,
   2. value to a user,
   3. actions carried out under certain conditions.
2. Apply the 3 C's ([User Stories Guide](https://habr.com/ru/post/577420)):
   1. Card — compactness, "fits on a card";
   2. Conversation — discussion of US;
   3. Confirmation — confirmation by the user and the development team.
3. Check the INVEST criteria ([Basics of user stories](https://habr.com/ru/company/luxoft/blog/84030/)):
   1. Independent: seek US independence;
   2. Negotiable: ability to discuss with the user, the customer, the team;
   3. Valuable: identify the usefulness of user actions described in the US;
   4. Estimable: estimate costs and work of middle and higher level specialists
   5. Small: autonomy and small size;
   6. Testable: apply:
      1. Acceptance criteria,
      2. Test scenarious.

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

### Exercise 00 — Description of User Stories <div id="51"></div>

Create at least 2 US for a manager for task 1:

1. Define at least two of the manager's needs in our system.
2. Write a US for each need:
   1. specify the US identifier;
   2. specify the US header — an active verb expression of the user's goal;
   3. describe US:
      1. specify the user role, 
      2. specify the benefit (value) to the role,
      3. specify the required action(s).
3. Develop acceptance criteria for one of the US, describe:
   1. precondition — the circumstances, the role of the user;
   2. actions performed by the user in the system;
   3. result — value to the user.
4. Develop a test scenario for the second US, describe:
   1. preconditions: on what data to check, what settings, what actions should precede;
   2. actions: what should be done by the user and the system;
   3. expected result: what will confirm the correctness of the execution.
5. Indicate your answers in the file ex00\_<product prefix>\_us\_<role>.docx.

### Exercise 01 — User Stories Coordination <div id="52"></div>

Create at least 4 more US's for task 1.

1. Select two roles other than manager in task 1.
2. Identify at least two needs for each role in our system.
3. Describe the US for each need by applying the requirements of paragraph 2 ex.00.
4. Describe the acceptance criteria for each selected role, one US at a time, applying the requirements of paragraph 3 ex.00.
5. Describe a test scenario for each selected role applying the requirements of paragraph 4 ex.00.
6. Indicate your answers in the file ex01\_<product prefix>\_us\_<role>.docx.

### Exercise 02 — User Stories Coordination <div id="53"></div>

Discuss and agree on the US developed.

1. Find one or more people among your fellow students or friends with whom you can discuss US by playing the roles of "user", "customer", "developer" one by one or together. 
2. During the discussion, make sure that the conditions of 3 Cs are met:
   1. Card: if the US doesn't fit enough, then split it into two or more or rework the US differently;
   2. Conversation: Discuss each of the US with each role. Refine the US if necessary;
   3. Confirmation: as a result of discussion and refinement, harmonize US with each role;
   4. Write a minutes of the discussion, specify:
      1. Who participated in the discussion;
      2. What role they played;
      3. What changes have been made to the US;
      4. Reasons for the changes.
3. When discussing check the three characteristics of INVEST:
   1. independence of each US; if there is a dependency — make them independent. If not — specify the dependency: which US depends on which (this will be needed for prioritization — in what order to implement US, in what order to check);
   2. negotiability of each US: whether it was discussed with "user", "customer", "developer" — indicate what conclusions were reached;
   3. value — confirm that the business value of each US is understood; if the business value is not understood, it is a reason to enlarge the US or rework it.
4. Identify each change, explain the reason for the change, record it.
5. Indicate your answers in the file ex02\_<product prefix>\_us.docx.
