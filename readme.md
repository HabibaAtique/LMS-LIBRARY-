# LIBRARY MANAGEMENT SYSTEM
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
