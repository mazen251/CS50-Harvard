# Week-7: SQL

SQL (Structured Query Language) is used to interact with relational databases.

**Key Concepts:**

- **Tables:** Store data in rows and columns
- **Schemas:** Define the structure of tables
- **Queries:** Used to retrieve and manipulate data



**SQL Queries**

- **SELECT Statement:** Retrieves data from one or more tables. <br>
  `SELECT column1, column2 FROM table_name;`


- **WHERE Clause:** Filters results based on conditions. <br>
  `SELECT column1, column2 FROM table_name WHERE condition;`


- **JOIN Operations:** Combines rows from two or more tables based on a related column
  - **INNER JOIN:** Retrieves records with matching values in both tables
  - **LEFT JOIN:** Retrieves all records from the left table, and matched records from the right table
  - **RIGHT JOIN:** Retrieves all records from the right table, and matched records from the left table
  - **FULL JOIN:** Retrieves records when there is a match in one of the tables


**Data Manipulation**

- **INSERT INTO:** Adds new records to a table. <br>
  `INSERT INTO table_name (column1, column2) VALUES (value1, value2);`

- **UPDATE:** Modifies existing records. <br>
  `UPDATE table_name SET column1 = value1 WHERE condition;`

- **DELETE:** Removes records from a table. <br>
  `DELETE FROM table_name WHERE condition;`


**Data Integrity**

- **Primary Keys:** Unique identifiers for records in a table
- **Foreign Keys:** Define relationships between tables
- **Constraints:** Ensure data validity (NOT NULL, UNIQUE)


**Indexing**

- **Indexes:** Improve query performance by speeding up data retrieval.  <br>
  `CREATE INDEX index_name ON table_name (column_name);`


**Advanced SQL**

- **Subqueries:** Queries within queries <br>
`
  SELECT column1 FROM table_name WHERE column2 = (SELECT column2 FROM table_name WHERE condition);
`

- **Transactions:** Ensure a sequence of operations are executed as a single unit
`
  BEGIN TRANSACTION;
  -- SQL operations
  COMMIT;
`

**SQL Security**

- **Permissions:** Control access to data and database objects.
- **Injection Attacks:** Security risks from untrusted inputs. Use parameterized queries to mitigate.
