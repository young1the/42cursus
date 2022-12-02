import { Injectable, Logger } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { ChatEntity } from './entity/chat.entity';
import { ChatRoomEntity } from './entity/chatRoom.entity';
import * as bcrypt from 'bcrypt';
import { DmChannelEntity } from './entity/dmChannel.entity';
import { v4 as uuid } from 'uuid';
import { DMEntity } from './entity/dm.entity';
import { UserEntity } from 'src/user/entity/user.entity';

@Injectable()
export class ChatService {
  constructor(
    @InjectRepository(UserEntity)
    private userRepository: Repository<UserEntity>,
    @InjectRepository(ChatRoomEntity)
    private chatRoomRepository: Repository<ChatRoomEntity>,
    @InjectRepository(ChatEntity)
    private chatRepository: Repository<ChatEntity>,
    @InjectRepository(DMEntity)
    private dmRepository: Repository<DMEntity>,
    @InjectRepository(DmChannelEntity)
    private dmChannelRepository: Repository<DmChannelEntity>,
  ){}
  private logger = new Logger(ChatService.name);

  async createNewRoom(room) {
    try {
      const foundRoom = await this.chatRoomRepository.findOneBy({ name: room.name });
      if (!foundRoom) {

        const salt = await bcrypt.genSalt();
        const hash = await bcrypt.hash(room.password, salt);
        const newRoom = {
          owner_id: room.owner_id,
          name: room.name,
          access_modifier: room.access_modifier,
          password: hash,
          create_data: Date.now(),
          update_data: Date.now(),
        }
        const insertedRoom = await this.chatRoomRepository.insert(newRoom);
        return insertedRoom.raw[0];
      }
      return foundRoom;
    } catch(e) {

    }
  }

  async saveUser(user_id) {
    const newUser = {
      room: `${uuid()}`,
      user_id: user_id,
    }
    const insertedUser = await this.dmChannelRepository.insert(newUser);
    return insertedUser.raw[0];
  }

  async findUser(id) {
    const foundUser = await this.dmChannelRepository.findOneBy({ id: id });
    if (foundUser) {
      return foundUser;
    }
  }

  async saveDM(socket, msg) {
    const insertedDM = await this.dmRepository.insert({
      sender: socket.data.user_id,
      chat: msg,
      time: Date.now(), 
    });
    return insertedDM.raw[0];
  }

  async findRoom(nickname) {
    const userId = (await this.userRepository.findOneBy({ nickname: nickname })).id;
    return (await this.dmChannelRepository.findOneBy({ user_id: userId })).room;
  }
}
