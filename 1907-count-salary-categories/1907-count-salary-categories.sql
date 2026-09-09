SELECT 'Low Salary' AS category,
    COALESCE(SUM(CASE WHEN income < 20000 THEN 1 ELSE 0 END),0) AS accounts_count
FROM Accounts
UNION
SELECT 'Average Salary' AS category,
    COALESCE(SUM(CASE WHEN income BETWEEN 20000 AND 50000 THEN 1 ELSE 0 END),0) AS accounts_count
FROM Accounts
UNION
SELECT 'High Salary' AS category,
    COALESCE(SUM(CASE WHEN income > 50000 THEN 1 ELSE 0 END),0) AS accounts_count
FROM Accounts;
