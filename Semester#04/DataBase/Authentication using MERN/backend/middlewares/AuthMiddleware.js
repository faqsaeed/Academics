import jwt from "jsonwebtoken"
import dotenv from "dotenv"

dotenv.config();
const JWTSECRET = process.env.JWT_SECRET; 

export const verifyToken = (req, res, next) => {
    const token = req.header("Authorization");

    if (!token) 
        return res.status(401).json({ error: "Access denied. No token provided." });

    try {
        const decoded = jwt.verify(token.replace("Bearer ", ""), JWTSECRET);
        req.user = decoded;
        next(); // Add this to proceed to the next middleware
    } 
    catch (error) {
        return res.status(403).json({ error: "Invalid or expired token" });
    }
};