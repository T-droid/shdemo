
#!/usr/bin/python3

import cmd
from models import storage  # Import the storage module to work with data storage
from models.base_model import BaseModel

class HBNBCommand(cmd.Cmd):
    prompt = "(hbnb) "

    def do_all(self, arg):
        """
        Prints all string representations of instances, filtered by class name
        (if provided).
        """
        all_instances = storage.all()  # Use the storage module to get all instances
        if not arg:
            all_instances = {k: v for k, v in all_instances.items() if k != "BaseModel." + k.split('.')[1]}
            # Filter out "BaseModel" instances when class name is not provided
            for instance in all_instances.values():
                print(instance)
        else:
            class_name = arg.strip()
            valid_classes = ["Amenity", "BaseModel", "City", "Place", "Review", "State", "User"]
            if class_name not in valid_classes:
                print("** class doesn't exist **")
            else:
                filtered_instances = {k: v for k, v in all_instances.items() if k.startswith(class_name + ".")}
                for instance in filtered_instances.values():
                    print(instance)

    def do_create(self, arg):
        """
        Creates a new instance of BaseModel, saves it to the JSON file,
        and prints the ID.
        """
        if not arg:
            print("** class name missing **")
            return
        class_name = arg.strip()
        valid_classes = ["Amenity", "BaseModel", "City", "Place", "Review", "State", "User"]
        if class_name not in valid_classes:
            print("** class doesn't exist **")
            return
        new_instance = BaseModel()
        new_instance.save()  # Save the new instance to the JSON file
        print(new_instance.id)

    def do_update(self, arg):
        """
        Updates an instance based on the class name and id
        by adding or updating an attribute.
        """
        if not arg:
            print("** class name missing **")
            return
        args = arg.split()
        if len(args) < 2:
            print("** instance id missing **")
            return
        class_name = args[0]
        instance_id = args[1]
        valid_classes = ["Amenity", "BaseModel", "City", "Place", "Review", "State", "User"]
        if class_name not in valid_classes:
            print("** class doesn't exist **")
            return
        objects = storage.all()  # Use the storage module to get all instances
        key = "{}.{}".format(class_name, instance_id)
        if key not in objects:
            print("** no instance found **")
            return
        if len(args) < 3:
            print("** attribute name missing **")
            return
        if len(args) < 4:
            print("** value missing **")
            return
        attribute_name = args[2]
        attribute_value = args[3]
        if attribute_name in ['id', 'created_at', 'updated_at']:
            print("** cannot update id, created_at, or updated_at **")
            return
        instance = objects[key]
        setattr(instance, attribute_name, attribute_value)
        instance.save()  # Save the updated instance to the JSON file

    def do_destroy(self, arg):
        """
        Deletes an instance based on the class name and id.
        """
        if not arg:
            print("** class name missing **")
            return
        args = arg.split()
        if len(args) < 2:
            print("** instance id missing **")
            return
        class_name = args[0]
        instance_id = args[1]
        valid_classes = ["Amenity", "BaseModel", "City", "Place", "Review", "State", "User"]
        if class_name not in valid_classes:
            print("** class doesn't exist **")
            return
        objects = storage.all()  # Use the storage module to get all instances
        key = "{}.{}".format(class_name, instance_id)
        if key in objects:
            del objects[key]
            storage.save()  # Save the updated instance to the JSON file
        else:
            print("** no instance found **")

    def do_show(self, arg):
        """
        Prints the string representation of an instance based on the class name and id.
        """
        if not arg:
            print("** class name missing **")
            return
        args = arg.split()
        if len(args) < 2:
            print("** instance id missing **")
            return
        class_name = args[0]
        instance_id = args[1]
        valid_classes = ["Amenity", "BaseModel", "City", "Place", "Review", "State", "User"]
        if class_name not in valid_classes:
            print("** class doesn't exist **")
            return
        key = "{}.{}".format(class_name, instance_id)
        all_instances = storage.all()  # Use the storage module to get all instances
        if key in all_instances:
            print(all_instances[key])
        else:
            print("** no instance found **")

    def do_quit(self, arg):
        """Exit the program."""
        return True

    def do_EOF(self, arg):
        """Exit the program."""
        return True

if __name__ == "__main__":
    cmd = HBNBCommand()
    cmd.cmdloop()