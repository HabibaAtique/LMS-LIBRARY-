# LIBRARY MANAGEMENT SYSTEM
PROJECT AIMS AND OBJECTIVES
The project aims and objectives that will be achieved after completion of this project arediscussed in this subchapter. The aims and objectives are as follows:

 
Online book issue
 

 
Request column for librarian for providing new books
 

 
A separate column for digital library
 

 
Student login page where student can find books issued by him/her and date of return.
 

 
A search column to search availability of books

 
A teacher login page where teacher can add any events being organized in the collegeand important suggestions regarding books.
 

 
Online notice board about the workshop.

Here are the main classes of our Library Management System:

Library: The central part of the organization for which this software has been designed. It has attributes like ‘Name’ to distinguish it from any other libraries and ‘Address’ to describe its location.

Book: The basic building block of the system. Every book will have ISBN, Title, Subject, Publishers, etc.

BookItem: Any book can have multiple copies, each copy will be considered a book item in our system. Each book item will have a unique barcode.

Account: We will have two types of accounts in the system, one will be a general member, and the other will be a librarian.

LibraryCard: Each library user will be issued a library card, which will be used to identify users while issuing or returning books.

BookReservation: Responsible for managing reservations against book items.

BookLending: Manage the checking-out of book items.

Catalog: Catalogs contain list of books sorted on certain criteria. Our system will support searching through four catalogs: Title, Author, Subject, and Publish-date.

Fine: This class will be responsible for calculating and collecting fines from library members.

Author: This class will encapsulate a book author.

Rack: Books will be placed on racks. Each rack will be identified by a rack number and will have a location identifier to describe the physical location of the rack in the library.

Notification: This class will take care of sending notifications to library members.
