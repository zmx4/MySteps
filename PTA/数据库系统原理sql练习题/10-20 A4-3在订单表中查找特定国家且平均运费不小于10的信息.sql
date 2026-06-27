CREATE TABLE `orders` (
`OrderID`  int(11) NOT NULL ,
`CustomerID`  varchar(5) ,
`EmployeeID`  int(11),
`OrderDate`  datetime,
`RequiredDate`  datetime,
`ShippedDate`  datetime,
`ShipVia`  int(11),
`Freight`  decimal(10,4) NULL DEFAULT 0.0000 ,
`ShipName`  varchar(40) ,
`ShipAddress`  varchar(60) ,
`ShipCity`  varchar(15) ,
`ShipRegion`  varchar(15) ,
`ShipPostalCode`  varchar(10) ,
`ShipCountry`  varchar(15) ,
PRIMARY KEY (`OrderID`)
);
SELECT 
    CustomerID, 
    AVG(Freight) AS avgFreight 
FROM 
    orders 
WHERE 
    ShipCountry IN ('Belgium', 'Switzerland') 
GROUP BY 
    CustomerID 
HAVING 
    AVG(Freight) >= 10;