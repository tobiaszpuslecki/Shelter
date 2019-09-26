
       string cs = @"server=localhost;userid=user12;
           password=34klq*;database=mydb";

       MySqlConnection conn = null;

       try
       {
         conn = new MySqlConnection(cs);
         conn.Open();
         Console.WriteLine("MySQL version : {0}", conn.ServerVersion);

       } catch (MySqlException ex)
       {
         Console.WriteLine("Error: {0}",  ex.ToString());

       } finally
       {
         if (conn != null)
         {
             conn.Close();
         }
       }







       string cs = @"server=localhost;userid=user12;
           password=34klq*;database=mydb";

       MySqlConnection conn = null;

       try
       {
         conn = new MySqlConnection(cs);
         conn.Open();

         MySqlCommand cmd = new MySqlCommand();
         cmd.Connection = conn;
         cmd.CommandText = "INSERT INTO Authors(Name) VALUES(@Name)";
         cmd.Prepare();

         cmd.Parameters.AddWithValue("@Name", "Trygve Gulbranssen");
         cmd.ExecuteNonQuery();

       } catch (MySqlException ex)
       {
         Console.WriteLine("Error: {0}",  ex.ToString());

       } finally
       {
           if (conn != null) {
               conn.Close();
           }

       }





       string cs = @"server=localhost;userid=user12;
           password=34klq*;database=mydb";

       MySqlConnection conn = null;
       MySqlDataReader rdr = null;

       try
       {
           conn = new MySqlConnection(cs);
           conn.Open();

           string stm = "SELECT * FROM Authors";
           MySqlCommand cmd = new MySqlCommand(stm, conn);
           rdr = cmd.ExecuteReader();

           while (rdr.Read())
           {
               Console.WriteLine(rdr.GetInt32(0) + ": "
                   + rdr.GetString(1));
           }

       } catch (MySqlException ex)
       {
           Console.WriteLine("Error: {0}",  ex.ToString());

       } finally
       {
           if (rdr != null)
           {
               rdr.Close();
           }

           if (conn != null)
           {
               conn.Close();
           }

       }
