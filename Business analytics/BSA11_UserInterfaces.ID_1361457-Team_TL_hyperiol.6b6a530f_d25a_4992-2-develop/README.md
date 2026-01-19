# User Interaction Design

Summary:
Designing visual forms is the responsibility of the UI designer. But usually the UI designer is not familiar with the importance of this task. The content of the screen forms and the movement between them is the responsibility of the analyst or UX designer, if there is one on the team. In this project, you will look at UI design from the analyst's perspective, and what the analyst should delegate to the designer to make visual interfaces user-friendly.

💡 [Tap here](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624) **to leave your feedback on the project**. It's anonymous and will help our team make your educational experience better. We recommend completing the survey immediately after the project.

## Contents

- [Chapter I](#chapter-i)
   - [Preamble](#preamble)
- [Chapter II](#chapter-ii)
   - [General Rules](#general-rules)
- [Chapter III](#chapter-iii)
   - [1. Data Presentation Form](#1-data-presentation-form)
   - [2. Roles and Key Scenarios](#2-roles-and-key-scenarios)
   - [3. Screen Forms](#3-screen-forms)
- [Chapter IV](#chapter-iv)
   - [Description of tasks](#description-of-tasks)
   - [Task 1. Haircut Appointment](#task-1-haircut-appointment)
- [Chapter V](#chapter-v)
   - [Exercise 00 — Choosing the Form of Product Presentation](#exercise-00--choosing-the-form-of-product-presentation)
   - [Exercise 01 — Screen Forms of Classifiers and References](#exercise-01--screen-forms-of-classifiers-and-references)
   - [Exercise 02 — Data on the Screen Forms of Classifiers and References](#exercise-02--data-on-the-screen-forms-of-classifiers-and-references)
   - [Exercise 03 — Key Role Scenarios](#exercise-03--key-role-scenarios)
   - [Exercise 04 — List of Screen Forms](#exercise-04--list-of-screen-forms)
   - [Exercise 05 — Screen Forms](#exercise-05--screen-forms)
   - [Exercise 06 — Controls Description](#exercise-06--controls-description)

## Chapter I

![Illustration](misc/images/IMG_6494.jpg)

### Preamble

Often the user interface is thought of as screen forms. In fact, visual forms are only one part of the user interface. 

When designing the UI for IT systems, three components come together: 

- The form in which data is presented;
- The role behavior of users in the system; 
- Content — the data on which actions are performed.

**UX/UI design** deals with all of these. It is the design of any user interface where usability is as important as appearance.

**UX** means user experience. In other words, it's what kind of experience/impression the user gets from working with your interface. Whether he/she is able to achieve a goal and how easy or difficult it is to do so.

**UI** means user interface. What the interface looks like and what visual and tactile properties it has. It determines the color scheme, the usability of signals, the readability of text, and so on.

### Literature:

1. Karl Wiegers, Joy Beatty, "Software Requirements" 3rd edition, amplified. 
2. Alan Cooper, Robert Reimann, David Cronin "About Face: The Essentials of Interaction Design".
3. Y. Kupriyanov "[Requirements don't change, you're the one who failed to identify them. 10 techniques for checking the completeness of requirements](https://conf.uml2.ru/class/trebovaniya-ne-menyayutsya-eto-vy-ikh-nedovyyavili--10-tekhnik-proverki-polnoty-trebovanii.html)" LAF, 2018.
4. https://rutube.ru/video/e2575de02c74c784e1c3fd970bdcc018/?ysclid=m0m8n58e56609048185
5. https://www.internet-technologies.ru/articles/kak-sozdat-poleznyy-wireframe.html
6. https://habr.com/ru/post/158399/
7. Balsamiq и Figma [1/17 Welcome to the course! Balsamiq and Figma. Layout course for analysts — YouTube](https://rutube.ru/video/e2575de02c74c784e1c3fd970bdcc018/?ysclid=m0m8n58e56609048185).

## Chapter II

### General Rules

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

## Chapter III 

### 1. Data Presentation Form

The user experience depends largely on whether the application is appropriate for the device on which it runs and whether the device meets the user's needs. For example, calling a taxi or buying movie tickets using only a desktop computer and a high-resolution monitor is unlikely to satisfy the general public, and using a graphics editor on a mobile phone is unlikely to appeal to computer graphics specialists. Or sometimes it is important that the interface allows working in limited lighting conditions. The analyst should describe these parameters to the designer and, if necessary, specify several factors. For example, the system should work both on a desktop computer and on a mobile phone, and in this case designers often create two different visual interfaces.

Therefore, the form of data presentation should be described as follows

1. The form factor of the product being designed. What kind of systems and devices it will be used on:
   - An application for everyday use at home on a cell phone; 
   - A specialized application for a computer with a high resolution monitor;
   - An application on a laptop/tablet for clients with a backlit keyboard;
   - A system for a kiosk in a public place.
2. Type of application: marketplace, enterprise system, gaming application, highly specialized system.
3. Control method: keyboard, mouse, joystick, voice call.
4. Localization requirements: geographical, language, time zone, other.
5. Special features: special features for disabled users.

### 2. Roles and Key Scenarios

Scenario is a visual schematic representation of how the user solves his/her task with the help of the site/program, what helps him/her and what prevents him/her from achieving the goal.

A key scenario is the interaction of a user in a particular role with the system in the context of his/her target tasks. For example, for a barbershop client, the target task is to book a service. And the registration task is not the target task, but only the one that provides the ability to book the service after registration.

When working out the key scenarios, sketches of tasks or parts of tasks are created. They are linked together to get a holistic picture of the process. An example of a key scenario is the dialog box map shown in Chapter 12 of Karl Wiegers' book.

### 3. Screen Forms

Depending on the team environment, the analyst may develop layouts (sketches), prototypes, and describe functions called in the screen interface, referring to standards adopted by the team.

When two or more roles use the same data, even with different functions such as reading and correcting, it is better if both screens and data are similar in visualization. This is useful so that when a person changes roles, they don't have to get used to a different interface all over again.

Usually, the screen is divided into separate areas — frames. Each frame contains:

1) a list of instances of an entity (object) with a list of attributes by which an individual instance can be easily identified;
2) a card with attributes of an instance;
3) related entities (list or card) or transition to related objects.

Additional operations should be provided:

- searching,
- filtering,
- sorting.

Also specify:

1) searching/filtering/sorting fields,
2) for searching: match accuracy,
3) for filtering/sorting: whether to save the filter/sorting or not.

It is useful to draw a UI sketch even by hand, scan it and attach it to the description. Comfortable sketches (layouts, mocaps) can be done with Balsamiq and Figma tools.

## Chapter IV 

### Description of tasks

### Task 1. Haircut Appointment 

The management of a chain of barbershops decided to implement an online booking system. The main objective is to develop the business by expanding the customer base through the possibility of online registration, as well as to reduce employee labour costs and manual labour by automatically informing customers through communication channels. 

Both registered and unregistered visitors can book an appointment on the website. When making an appointment, they can select the type of service: hairdressing or cosmetology, as well as the service itself, the master and the time from the available intervals. The system should provide automatic sending of reminders to clients through the communication channel chosen by the client (Telegram, WhatsApp, VK, SMS) according to the schedule set by the manager. After receiving a service, the system offers the client to evaluate the service and write suggestions on how to improve the work.

The schedule of masters and the services provided by each master should be entered by the manager, who may be more than one person. This person is also responsible for keeping the schedule up to date and adjusting it if necessary, communicating with customers manually, marking the service, charging and accepting payment, sending the payment data to the accounting department. The manager can also receive reports on completed services and view customer feedback.

Each master has the ability to view the schedule and appointments for their services, as well as customer reviews.  

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
2. The client enters their phone number and name (patronymic).
3. The system confirms that the phone is not registered in the system.
4. The client enters the preferred password.
5. The system informs the password level (weak, medium, high).
6. The system registers the client, sends SMS to the client about registration with name and login.

**Alternative scenario:**

1. The entered phone number is registered in the system:
   1. The system reports that such a phone number is registered in the system.
   2. The client enters another phone number (2.) or refuses to register.

**UC04 Register Client (Manager)**

**Use context:** A manager, when communicating with a client over the phone, registers the client to book a service.

**Scope:** barbershop, providing services to clients.

**Level:** User goal.

**Main actor:** Manager.

**Preconditions:** A client called the manager. The manager accessed the barbershop's website.

**Main scenario:**

1. The manager opens the client registration page.
2. The manager enters the phone number and name provided by the client over the phone.
3. The system confirms that the phone is not registered in the system.
4. The system registers the client, generates a temporary password, sends a SMS to the client's phone about registration with name, login, temporary password.

**Alternative scenario:**

1. The entered phone is registered in the system:
   1. The system informs that this such phone number is registered in the system.
   2. Client enters another phone number (2.) or refuses to register.

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

1. The selected slot is booked in the system by the client. 
   1. The system reports that the selected slot is booked in the system by the client. 
   2. The manager contacts the client by phone and arranges to reschedule the visit to another time or to another master, enters the information into the system. 
   3. The system sends an SMS to the client about the change of time and/or master of the visit.

**UC03 Book a service slot**

**Use context:** Client wants to book a barbershop visit.

**Scope:** barbershop, providing services to clients.

**Level:** User goal.

**Main actor:** client.

**Preconditions:** The client has logged into the website.

**Main scenario:**

1. The client opens the slot selection page.
2. The system generates a list of available slots.
3. The client selects a time service slot (date, time) from the available slots.
4. The system generates a list of services to choose from.
5. The client selects a service from the available ones.
6. The system generates a list of selectable masters.
7. The client selects one of the available masters.
8. The system confirms that the selected slot is not booked in the system by another client.
9. The client confirms the slot reservation.
10. The system allocates the slot: date, time, master, service.
11. The system sends the client an SMS about the service reservation to the phone number specified during registration.

**Alternative scenarios:**

1. Slot selection by service:
   1. The client selects a service from the list of services provided by specialists from the Employee Role entity.
   2. The client selects a free service slot for the master.
   3. The system displays free slots in the master's schedule.
   4. The client can view the schedule.
   5. The client selects one of the available slots.
   6. The system sends an SMS to the client's phone number about booking a slot (date, time).
2. Slot selection by the master.

## Chapter V

### Exercise 00 — Choosing the Form of Product Presentation

For task 1, specify the form of product presentation:

1. Specify the device(s) on which the software product will be used. 
2. Specify the type of the software product.
3. Specify the method(s) for managing the product.
4. Specify the localization need(s).
5. Present in tabular form.

### Exercise 01 — Screen Forms of Classifiers and References

For Task 1, describe the screen forms of classifiers and references.

1. Make a list of classifiers and references, specify:
   1. name of the classifier/reference; 
   2. related references and classifiers that are required to be filled in.
2. Develop (draw by any method) layouts (sketches) of the screen forms of classifiers/references:
   1. specify the name of the classifier/references;
   2. select the frame of the list form;
   3. specify the frame of operations (main and supporting);
   4. specify the calls of operations, transition further and refusal from the operation. 
3. Describe the basic operations for classifiers and references:
   1. access rights by roles to operations;
   2. conditions of operations execution;
   3. the result of the operation depending on the conditions:
      1. in the classifier;
      2. in other parts of the system. 
4. Describe additional operations:
   1. sorting, sorting fields, default state;
   2. filtering, filter fields, saving filters, no result messages;
   3. searching, search fields, match accuracy, no result messages;
   4. duplication from another record when adding (if any);
   5. calculating sums (if any).
5. Specify logging:
   1. operations that require logging;
   2. attributes stored during logging;
   3. command fields that require logging (date, time, user, other).
6. Submit results in tabular form in multiple tables.

### Exercise 02 — Data on the Screen Forms of Classifiers and References

For Task 1, describe the data on the screen forms of the classifiers and references. For each classifier and reference, specify:

1. The fields on the list screen:
   1. short name of the field;
   2. description;
   3. presentation format:
      1. type;
      2. length (if text);
      3. mandatory or not;
      4. default value;
      5. visualization of fields in case of undefined values;
      6. method of visualization in case of fields exceeding the screen boundaries;
      7. selection from the classifier/reference;
      8. conditions/restrictions/checks;
      9. error/warning messages.
2. Describe the needs for:
   1. pagination (numbering of records);
   2. calculation of sums (number of records / sum / average / etc.).
3. Checks and error messages for incorrect data entry.
4. Submit the result in tabular form.

### Exercise 03 — Key Role Scenarios

For Task 1: 

1. Develop key process scenarios of main processes for each role:
   1. manager,
   2. master,
   3. client.
2. Develop task diagrams of the main processes for each role:
   1. Illustrate tasks with rectangles;
   2. Illustrate the transition of the main successful scenario between tasks with arrows.
3. Create key scripts for executing the main processes of each role:
   1. Illustrate the screen forms in rectangles;
   2. Indicate each permissible transition possibility as an arrow;
   3. Specify the condition of transition (action or transition to action) on the arrows in a form that is clear enough for development;
   4. Provide for exit before the end of the process, without saving the results;
   5. Specify the main purpose of each screen.
4. Indicate the beginning and end with the corresponding elements.

### Exercise 04 — List of Screen Forms

For Task 1: 

1. Describe the main process screens for the roles:
   1. manager,
   2. master,
   3. client.
2. Make a list of screen forms, specify:
   1. screen identifier;
   2. main purpose (main action) by role;
   3. other actions of the role;
   4. data required to perform the action; 
   5. access rights of each role to the data represented in the screen.
3. Submit in tabular form.

### Exercise 05 — Screen Forms

For Task 1, for each screen form listed in Ex.04:

1. Develop (draw by any method) the layout (sketch) of the screen form, specify:
   1. the name of the form;
   2. the frame(s) of the main operation;
   3. frame(s) of other operations;
   4. calls of operations, transition and cancel operations;
   5. data frames (list and card);
   6. the role(s) of the users to whom the screen is accessible.
2. Describe main operations:
   1. access rights by roles to the operation;
   2. conditions of operations execution;
   3. the result of the operation depending on the conditions:
      1. on the data in the current window,
      2. in other parts of the system. 
3. Describe additional operations:
   1. sorting, sort fields, default state;
   2. filtering, filter fields, saving filters, messages in case of no result;
   3. searching, search fields, match accuracy, messages in case of no result;
   4. duplication from another record when adding (if any);
   5. calculation of totals (if any).
4. Data description:
   1. specify the object / class of data;
   2. describe the form of the data list:
      1. pagination,
      2. short name of the field,
      3. mnemonics (if any),
      4. description,
      5. presentation format (see ex.02, 1.c.);
   3. describe the form of the data card:
      1. pagination,
      2. short name of the field,
      3. description,
      4. presentation format (see ex.02, 1.c.).
5. Specify logging:
   1. operations requiring logging;
   2. attributes stored during logging;
   3. service fields requiring logging.  
6. Present the results in tabular form, possibly in several tables.

### Exercise 06 — Controls Description

For Task 1, describe the controls for inputting and correcting on screen forms.

1. For each screen form containing input/correction operations, specify:
   1. screen identifier;
   2. role(s);
   3. the main purpose (main action) in the context of the role(s);
   4. object (class) containing the data presented on the screen.
2. Description of controls:
   1. pagination,
   2. field name,
   3. field mnemonic (if any),
   4. control description,
   5. error message in case of negative control completion,
   6. result of the operation in case of negative control completion,
   7. result of the operation in case of positive completion of the control.
3. Specify the need for logging in case of negative control completion. 
4. Specify logging parameters:
   1. operations requiring logging;
   2. attributes stored during logging;
   3. service fields requiring logging.  
5. Present in tabular form.
