SELECT e.name, eu.unique_id
FROM Employees AS e
LEFT JOIN EmployeeUNI AS eu
ON e.id = eu.id;