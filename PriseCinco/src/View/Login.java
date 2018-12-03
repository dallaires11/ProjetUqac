package View;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.scene.control.PasswordField;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import Controller.ConnectionSQL;
import Model.SessionBD;
import javafx.stage.Stage;
import org.hibernate.Session;

public class Login {
    private Scene loginScreen;
    private FilmSearch searchScreen;
    private TextField pseudo;
    private PasswordField password;
    private Text title,labPseudo,labPassword,incorrect;
    private final VBox org1;
    private final HBox org2;
    private final Group root;
    private final Button submit;
    private final ConnectionSQL comm;
    private final Stage theStage;
    private SessionBD sessionBD;
    
    public Login(Stage stage,FilmSearch searchScreen,Session session){
        comm = new ConnectionSQL(session);
        this.searchScreen = searchScreen;
        theStage = stage;
        
        title = new Text("Connection client");
        labPseudo = new Text("Entrer votre nom d'utilisateur");
        labPassword = new Text("Entrer votre mot de passe");
        incorrect = new Text("Tentative de connection echoue, veuillez recommencer");

        submit = new Button("Se connecter");
        
        pseudo = new TextField();
        password = new PasswordField();

        

        org1=new VBox();
        org1.getChildren().addAll(title,labPseudo,pseudo,labPassword,password,submit,incorrect);
        
        
        org2=new HBox();
        org2.getChildren().addAll(org1);

        setAction();
        setText();
        setPosition();

        root=new Group();
        root.getChildren().add(org2);

        loginScreen = new Scene(root,1400,900);
    }
    
    public Scene getScene(){
        return loginScreen;
    }
    
    private void setAction(){
        submit.setOnAction(event -> {
            System.out.println("test de connection");
            if(comm.tryConnection(pseudo.getText(),password.getText())){
                submit.setDisable(true);
                submit.setVisible(false);
                incorrect.setVisible(false);
                searchScreen.setSessionBd(comm.getCurSession());
                theStage.setScene(searchScreen.getScene());
                //sessionBD = new SessionBD(pseudo.getText(),password.getText());
            }
            else
                incorrect.setVisible(true);
        });
        
    }
    
    private void setText(){
        title.setScaleX(1.5); title.setScaleY(1.5);
        incorrect.setVisible(false);

    }
    
    private void setPosition(){
        org1.setTranslateX(50);
        org1.setTranslateY(15);
    }
}
