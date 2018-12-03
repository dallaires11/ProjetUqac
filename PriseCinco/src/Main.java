import Controller.NewHibernateUtil;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.image.Image;
import View.*;
import javafx.application.Platform;
import org.hibernate.Session;

public class Main extends Application {
    private Login loginView;
    private FilmSearch searchView;
    private Session session;
    
    
    @Override
    public void start(Stage primaryStage) {
        session = NewHibernateUtil.getSessionFactory().openSession();
        searchView =  new FilmSearch(session);
        loginView = new Login(primaryStage,searchView,session);
        
        
        
        primaryStage.setScene(loginView.getScene());
        primaryStage.getIcons().add(new Image("Ressource/logo.png"));
        primaryStage.setTitle("Club Video Le Corsaire Noir");
        primaryStage.show();
        
        
        primaryStage.setOnCloseRequest(event-> {            
                Platform.exit();
                NewHibernateUtil.getSessionFactory().close();
        });
    }

    public static void main(String[] args) {
        launch(args);
    }
    
}